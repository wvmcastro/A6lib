#include <A6lib.h>

// Instantiate the library with TxPin, RxPin.
A6lib A6l(7, 8);


//  Pin number by which the power of module is controlled.
#ifndef ESP8266
  #define module_powerpin 0
#else
  #define module_powerpin D0
#endif

void setup() {
    Serial.begin(115200);

    delay(1000);

    // Power-cycle the module to reset it.
    A6l.powerCycle(module_powerpin);
    A6l.blockUntilReady(9600);
}

void loop() {
    Serial.println("checking call status");
    callInfo cinfo = A6l.checkCallStatus();
    Serial.println("call status checked");

    delay(5000);

    
    if(cinfo.number!=NULL)
    {
      if (cinfo.direction == DIR_INCOMING && cinfo.number == "919999999999")
          A6l.answer();
      else
          A6l.hangUp();
      delay(1000);
    }
    else
    {
       Serial.println("no number yet");
       delay(1000);
    }
}