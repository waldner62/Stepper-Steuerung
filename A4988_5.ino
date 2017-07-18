
//Stepper-Motor-Steuerung mit A4988 und Taster von waldner 62

int dirArm = 3; // D3 am Arduino
int stepperArm = 2; // D2 am Arduino

void setup() {
pinMode(dirArm, OUTPUT);
 pinMode(stepperArm, OUTPUT);
 Serial.begin(9600);
}


 void Arm(boolean dir,int steps){
 
 digitalWrite(dirArm,dir);
 delay(50);
 
 while ( ! analogRead(A0)) // Wenn der Taster gdrückt wird dann drehen.
 for(int r=0;r<steps;r++){
    digitalWrite(dirArm, HIGH);  // Dreh - Richtung
   digitalWrite(stepperArm, HIGH);
   delayMicroseconds(5000);  // Geschwindigkeit
   digitalWrite(stepperArm, LOW);
   delayMicroseconds(5000);  // Geschwindigkeit
   

 }
while ( ! analogRead(A1)) // Wenn der Taster gdrückt wird dann drehen.
 for(int l=0;l<steps;l++){
    digitalWrite(dirArm, LOW);  // Dreh - Richtung
   digitalWrite(stepperArm, HIGH);
   delayMicroseconds(5000);  // Geschwindigkeit
   digitalWrite(stepperArm, LOW);
   delayMicroseconds(5000);  // Geschwindigkeit

 }
}
void loop(){
  
  Arm(true,1);  // Dreh - Richtung - HIGH
 Arm (false,1);  // Dreh - Richtung - LOW
 

}





