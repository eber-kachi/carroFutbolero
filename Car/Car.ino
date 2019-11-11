// Declaracion de variables
int LeftA = 5; // control de motor.  digital pin 5:
int LeftB = 6; // control de motor.  digital pin 6:
int rightA = 9;// control de motor.  digital pin 9:
int rightB = 10; // control de motor.  digital pin 10:
int acc = 250; // Velocidad
char state[1] ; // variable para almecenar lo que le llega por Serial

void setup()
{
  Serial.begin(9600);  
  pinMode(rightA, OUTPUT); // inicializando como  derecho A pin como salida
  pinMode(rightB, OUTPUT);// inicializando como  derecho B pin como salida
  pinMode(LeftA, OUTPUT); // inicializando como izquierda A pin como salida
  pinMode(LeftB, OUTPUT);// inicializando como izquierda A pin como salida
  // pinMode(son,OUTPUT);
}

void loop()
{
  if (Serial.available()>0)
  {
    state[0] = Serial.read();
    Serial.println(state[0]);
   //delay (20);
   Serial.flush();
  
  }
   Serial.flush();
   
  if (state[0] == 'a') //
  { // Para mover / acelerar el vehículo  hacia adelante
    Serial.println(state[0]);
    analogWrite(rightB, 0); 
    analogWrite(LeftB, 0); 
    analogWrite(rightA, acc);
    analogWrite(LeftA, acc);
  }
  if (state[0] == 'b')
  { //Para girar el coche a la izquierda
    Serial.println(state[0]);
    analogWrite(rightB, 0);
    analogWrite(LeftB, acc);
    analogWrite(LeftA, 0); 
    analogWrite(rightA, acc); 
  }
  if (state[0] == 'c')
  { //Para detener el coche
    Serial.println(state[0]);
    analogWrite(rightB, 0);
    analogWrite(LeftB, 0);
    analogWrite(rightA, 0);
    analogWrite(LeftA, 0);
  
  }
  if (state[0] == 'd')
  { // Para girar el auto a la derecha
    Serial.println(state[0]);
    analogWrite(rightB, acc); 
    analogWrite(LeftB, 0);
    analogWrite(rightA, 0);/
    analogWrite(LeftA, acc);
  }

  if (state[0] == 'e')
  { // Para revertir el auto
    Serial.println(state[0]);
    analogWrite(rightA, 0);
    analogWrite(LeftA, 0);
    analogWrite(rightB, acc);
    analogWrite(LeftB, acc);
  }
  state[0]='i';
}
void stop(){
  Serial.println(state);
  analogWrite(rightB, 0); 
  analogWrite(LeftB, 0);
  analogWrite(rightA, 0);
  analogWrite(LeftA, 0);
}
