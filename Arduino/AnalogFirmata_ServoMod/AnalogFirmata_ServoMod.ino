/*
 * Firmata is a generic protocol for communicating with microcontrollers
 * from software on a host computer. It is intended to work with
 * any host computer software package.
 *
 * To download a host software package, please clink on the following link
 * to open the download page in your default browser.
 *
 * http://firmata.org/wiki/Download
 */

/* This firmware supports as many analog ports as possible, all analog inputs,
 * four PWM outputs, and two with servo support.
 *
 * This example code is in the public domain.
 */
#include <Servo.h>
#include <Firmata.h>

/*==============================================================================
 * GLOBAL VARIABLES
 *============================================================================*/

/* servos */
Servo servo9, servo10; // one instance per pin
/* analog inputs */
int analogInputsToReport = 0; // bitwise array to store pin reporting
int analogPin = 0; // counter for reading analog pins
/* timer variables */
unsigned long currentMillis;     // store the current value from millis()
unsigned long previousMillis;    // for comparison with currentMillis

//NUESTROS
int pos;
int switchPin = 8;
Servo myservo;

//int motorPin = 11;
//int ledPin = 13;
//int motorLevel = 190;


/*==============================================================================
 * FUNCTIONS                                                                
 *============================================================================*/

void analogWriteCallback(byte pin, int value)
{
    switch(pin) {
    //case 9: servo9.write(value); break;
    case 10: servo10.write(value); break;
    case 3: 
    case 5: 
    case 6: 
    case 11: // PWM pins
        analogWrite(pin, value); 
        break;
    }
}
// -----------------------------------------------------------------------------
// sets bits in a bit array (int) to toggle the reporting of the analogIns
void reportAnalogCallback(byte pin, int value)
{
    if(value == 0) {
        analogInputsToReport = analogInputsToReport &~ (1 << pin);
    }
    else { // everything but 0 enables reporting of that pin
        analogInputsToReport = analogInputsToReport | (1 << pin);
    }
    // TODO: save status to EEPROM here, if changed
}

/*==============================================================================
 * SETUP()
 *============================================================================*/
void setup() 
{
    Firmata.setFirmwareVersion(0, 2);
    Firmata.attach(ANALOG_MESSAGE, analogWriteCallback);
    Firmata.attach(REPORT_ANALOG, reportAnalogCallback);

    myservo.attach(9);
    //servo10.attach(10);
    Firmata.begin(57600);
    
    //digital
    pinMode(switchPin, INPUT);
    //pinMode(motorPin, OUTPUT);
    //pinMode(ledPin, OUTPUT);
}

/*==============================================================================
 * LOOP()
 *============================================================================*/
void loop() 
{
    while(Firmata.available())
        Firmata.processInput();
    currentMillis = millis();
    if(currentMillis - previousMillis > 20) {  
        previousMillis += 20;                   // run this every 20ms
        for(analogPin=0;analogPin<TOTAL_ANALOG_PINS;analogPin++) {
            if( analogInputsToReport & (1 << analogPin) ) 
                Firmata.sendAnalog(analogPin, analogRead(analogPin));
        }
    }
    
    //digital 
    if(digitalRead(switchPin) == HIGH)
    {
      // Setting position to center
      pos = myservo.read(); //reads "center" position from servo
      myservo.write(pos);  // assigns "center"position to servo 
      delay(5000);
        // setting rotation to another direction
      pos = pos - 1; 
      myservo.write(pos);
      delay(5000);
    } 
    else
    {
      pos = myservo.read();
      myservo.write(pos);
    }
    delay(50);
}

