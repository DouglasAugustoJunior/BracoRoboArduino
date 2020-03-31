#include <Servo.h>

/* Ideal deixar todos os motores nesse angulo para ajustar
o encaixe na direção correta*/
#define ANGULO_INICIAL_MOTOR 90 

// --- Mapeamento dos Joysticks ---
#define joystick1X A0
#define joystick1Y A1

#define joystick2X A2
#define joystick2Y A3

// --- Mapeamento dos Servos Motores ---
Servo motorBase;
Servo motorBraco1;
Servo motorBraco2;
Servo motorGarra;

void setup() {
  mapearPinosMotores();
  mapeiaJoystick();
  iniciaAngulosMotores();
}

void loop() {
  moverBase();
  moverBraco1();
  moverBraco2();
  moverGarra();
  delay(100);
}

// -------------- Funções Auxiliares --------------

void mapearPinosMotores(){
  motorBase.attach(5); // motor conectado no pino 5 porque é um PWM
  motorBraco1.attach(6); // motor conectado no pino 6 porque é um PWM
  motorBraco2.attach(9); // motor conectado no pino 9 porque é um PWM
  motorGarra.attach(10); // motor conectado no pino 10 porque é um PWM
}

void mapeiaJoystick(){
  pinMode(joystick1X, INPUT); // Joystick como input
  pinMode(joystick1Y, INPUT); // Joystick como input
  pinMode(joystick2X, INPUT); // Joystick como input
  pinMode(joystick2Y, INPUT); // Joystick como input
}

void iniciaAngulosMotores(){
  motorBase.write(ANGULO_INICIAL_MOTOR); // Posição inicial do motor
  motorBraco1.write(ANGULO_INICIAL_MOTOR); // Posição inicial do motor
  motorBraco2.write(ANGULO_INICIAL_MOTOR); // Posição inicial do motor
  motorGarra.write(ANGULO_INICIAL_MOTOR); // Posição inicial do motor
}

void moverBase(){
  // Pega a posição do joystyck1X
  int posX = analogRead(joystick1X);
  
  /* Mapeia a posição do joystyck para inserir no motor, pegando a posX,
  que vai de 0 a 1023 e convertendo para um valor entre 0 e 180 */
  posX = map(posX, 0, 1023, 0, 180);
  
  // Escreve o valor no motor
  motorBase.write(posX);
}

void moverBraco1(){
  // Pega a posição do joystyck1Y
  int posY = analogRead(joystick1Y);
  
  /* Mapeia a posição do joystyck para inserir no motor, pegando a posY,
  que vai de 0 a 1023 e convertendo para um valor entre 45 e 135 */
  posY = map(posY, 0, 1023, 45, 135);
  
  // Escreve o valor no motor
  motorBraco1.write(posY);
}

void moverBraco2(){
  // Pega a posição do joystyck2X
  int posX = analogRead(joystick2X);
  
  /* Mapeia a posição do joystyck para inserir no motor, pegando a posX,
  que vai de 0 a 1023 e convertendo para um valor entre 50 e 90 */
  posX = map(posX, 0, 1023, 50, 90);
  
  // Escreve o valor no motor
  motorBraco2.write(posX);
}

void moverGarra(){
  // Pega a posição do joystyck2Y
  int posY = analogRead(joystick2Y);
  
  /* Mapeia a posição do joystyck para inserir no motor, pegando a posY,
  que vai de 0 a 1023 e convertendo para um valor entre 90 e 130 */
  posY = map(posY, 0, 1023, 90, 130);
  
  // Escreve o valor no motor
  motorGarra.write(posY);
}