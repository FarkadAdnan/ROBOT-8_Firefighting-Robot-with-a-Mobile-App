/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
 
#include <AFMotor.h>
AF_DCMotor right_motor(1, MOTOR12_8KHZ);
AF_DCMotor left_motor(2, MOTOR12_8KHZ);
AF_DCMotor three_motor(3, MOTOR12_8KHZ);
String readString;

void setup() {
  Serial.begin(9600);
  right_motor.setSpeed(255);
  left_motor.setSpeed(255);
  three_motor.setSpeed(255);
  }
void loop() {
  while(Serial.available()){
    delay(50);
    char c=Serial.read();
    readString+=c;
  }
  if(readString.length()>0){
    Serial.println(readString);
    if (readString =="FORWARD"){  
      right_motor.run (FORWARD);
      left_motor.run (FORWARD);
      delay(500);
    }
    if (readString =="BACKWARD"){  
      right_motor.run (BACKWARD);
      left_motor.run (BACKWARD);
      delay(500);
    }
    if (readString =="LEFT"){  
      right_motor.run (FORWARD);
      left_motor.run (BACKWARD);
      delay(500);
    }
    if (readString =="RIGHT"){   
      right_motor.run (BACKWARD);
      left_motor.run (FORWARD);
      delay(500);
    }
    if (readString =="STOP"){   
      right_motor.run (RELEASE);
      left_motor.run (RELEASE);
      delay(500);
    }
    if (readString =="RUN WATER"){  
      three_motor.run (FORWARD);
      delay(500);
    }
    if (readString =="STOP WATER"){   
      three_motor.run (RELEASE);
      delay(500);
    }
  readString="";
  }
}
