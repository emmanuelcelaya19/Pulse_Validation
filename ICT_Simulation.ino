// Arduino Scripting File
// Project: ICT Simulation
// Customer: Jabil 
// Product: Janus
// Programmer: Emmanuel Celaya
// FCEO

bool Value = false;
bool Estado = true;

int BL20Signals[] = {4, 5, 6, 7, 8, 9, 10, 11};
int SignalsQuantity = 8;

void setup() 
{
 Serial.begin(9600); 

  for (int i = 0; i < SignalsQuantity; i = i + 1) 
  {
    pinMode(BL20Signals[i],OUTPUT);
    digitalWrite(BL20Signals[i],true);
  delay(150);
  digitalWrite(BL20Signals[i],false);
  }
  
}

void loop() {

  if(Serial.available() > 0 ){
  char Value = Serial.read();
  int Pin = random(4, 12);
  Serial.println(Pin);
if(Value=='1')
{
  digitalWrite(Pin,true);
  delay(150);
  digitalWrite(Pin,false);
}
if(Value=='0')
{
  digitalWrite(Pin,true);
  delay(50);
  digitalWrite(Pin,false);
}
Value = Serial.read();
Serial.flush();

  }


  

}
