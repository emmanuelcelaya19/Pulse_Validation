// Arduino Scripting File
// Project: ICT Communication
// Customer: Jabil 
// Product: Janus
// Programmer: Eng. Emmanuel Celaya
// FCEO


#define RelayON LOW
#define RelayOFF HIGH

bool Value;
bool Estado;
unsigned long tiempo1;
unsigned long tiempo2;
unsigned long IntervaloMillis = 100;

int ICTSignals[] = {22, 23, 24, 25, 26, 27, 28, 29};  // Relacion senales de entrada/Salida
int BL20Signals[] = {4, 5, 6, 7, 8, 9, 10, 11};       // Relacion senales de entrada/Salida
int SignalsQuantity = 8;                              // Cantidad de senales a trabajar

void setup() 
{
 Serial.begin(9600); 
  for (int i = 0; i < SignalsQuantity; i = i + 1) 
  {
    pinMode(ICTSignals[i],INPUT_PULLUP);  // Se inicializan los pines de lectura Input con un pull up resistencia a positivo
  }


  for (int i = 0; i < SignalsQuantity; i = i + 1) 
  {
    pinMode(BL20Signals[i],OUTPUT);           // Inicializacion de senales de salida 
    digitalWrite(BL20Signals[i],RelayOFF);    // Inicializacion de senales de salida en alto (apagar relays)
  }
  
}

void loop() { // Inicio Main Script

  for (int i = 0; i < SignalsQuantity; i = i + 1)   // Constantemente se leen las senales de entrada
  {
    Value = digitalRead(ICTSignals[i]);             // Se detecta flanco bajo inicio del pulso 
       if(Value == false)
       {
       tiempo1 = millis();                          // Se comienza a medir el pulso
       Serial.println(ICTSignals[i]);
          while(Value == false)
          {
              Value = digitalRead(ICTSignals[i]);   // se monitorea el termino del pulso 
          }
       tiempo2 = millis();                          // Finalizacion del pulso 
          if((tiempo2 - tiempo1) > IntervaloMillis) // Valida si el pulso es mayor de 100 milis prende envia un cero para prender la salida
             {
              Estado =  RelayON;
             }
           else
              Estado = RelayOFF;
              
       digitalWrite(BL20Signals[i],Estado); // Cambio de estado de la senal correspondiente
       }
  }

} // End Main Script
  
