//Bluetooth Mobile controlled Car

/* #Discribing -
 *  @author - Alan Jacob
 Here IN1 and IN2 are for controlling the LEFT side motors.
 Here IN3 and IN4 are for controlling the RIGHT side motors.

While in IN1 is used for LEFT side FORWARD and
         IN2 is used for LEFT side REVERSE/BACKWARDS

Similarly in IN3 is used for RIGHT side FORWARD and
             IN4 is used for RIGHT side REVERSE/BACKWARDS.       
               
*/

/* 
 *  So Pin number 13 and 12 is used for LEFT SIDE CONTROLLING
 *     Pin number 14 and 15 is used for RIGHT SIDE CONTROLLING

*/

#include<SoftwareSerial.h>
#define IN1 13                      //connecting IN1 pin of L298N with other arduino's pin no.13. We are defining which the variable and pin number.
#define IN2 12                                            // repeat this for every other
#define IN3 11          
#define IN4 10   
        
//We are using mySerial to take the input from pin number 0 and 1 which are connected to the Bluetooth module which will provide us with the input.


SoftwareSerial mySerial(0,1);                           // (0-> Rx , 1->Tx) 

                    /* We will be recieving 'Char' characters from the 0 and 1 pin and thus 
                         we need to declare the 'Char' variable named Bluetooth_Value*/                

char Bluetooth_Value;                                 

void setup() {
  // put your setup code here, to run once:
  pinMode(IN1,OUTPUT);  // declaring the pinMode and as we are giving input to the motor controller we will declare these pins as OUTPUT pins.
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

   digitalWrite(IN1,LOW); //At initial, the car should not move with any given instruction given to it so we are setting all pins to low.
   digitalWrite(IN2,LOW);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,LOW);

  mySerial.begin(9600); //declaring the baudrate of the recieving or transmission.

}

void loop() {
  // put your main code here, to run repeatedly:
char Data = mySerial.read();  //mySerial.read() is a predefined function which will read the recieving inputs from bluetooth module.
                              //Here the inputs from bluettoh will be in 'Char' format thus we will store the value in 'Char' variable.
   Bluetooth_Value = Data;    //passing the value from "Data" to "Bluetooth_Value".


/* Now we are using switch case here (you can use if-else statement too.

   We will pass the value to the switch case
*/ 
   switch(Bluetooth_Value){         

    case 'F':  // for forward
    digitalWrite(IN1,HIGH); // IN1 and IN3 are RIGHT AND LEFT FORWARD.
    digitalWrite(IN2,LOW); 
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW); 
    break;

    case 'B':   //for reverse
    digitalWrite(IN1,LOW); 
   digitalWrite(IN2,HIGH); //IN2 and IN4 are RIGHT and LEFT REVERSE.
   digitalWrite(IN3,LOW); 
    digitalWrite(IN4,HIGH);
    break;

    case 'S': // to stop
    digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
   digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
   break;

   case 'L': // for left
   digitalWrite(IN1,LOW); 
   digitalWrite(IN2,LOW); 
   digitalWrite(IN3,HIGH); // just right side motors will be used and thus it will turn the bot to left.
   digitalWrite(IN4,LOW); 
   break;

   case 'R': //for right
  digitalWrite(IN1,HIGH);  // just left side motors will be used and thus it will turn the bot to right.
  digitalWrite(IN2,LOW); 
  digitalWrite(IN3,LOW); 
  digitalWrite(IN4,LOW); 
   break;
   }

}
