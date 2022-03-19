/*
 *  Esse exemplo mostra como controlar dois motores utilizando o motor shield L293D e a biblioteca AFMotor
 *  
 *  Ligações:
 *  Motor Shield L293D instalado em cima do Arduino UNO
 *  Motor1 ligado no slot M1 do Shield
 *  Motor2 ligado no slot M2 do Shield
 *  Se alimentado por bateria externa, verificar a voltagem da bateria para não queimar o arduino (entre 6v e 12v).
 *  
 *  Notas:
 *  1 - Não existe maneira incorreta de ligar o motor. Se você está mandando ele andar pra frente, e ele anda pra trás,
 *      inverta os cabos positivo\negativo do motor. Se você manda virar pra direita, e ele vira pra esquerda, inverta
 *      o motor1 com o motor2
 *  2 - Com dois motores, apenas a alimentação USB provavelmente não vai ser o suficiente para fazê-los girar
 *  3 - Usar funções facilita a leitura e a programação - mesmo dando trabalho para criar as funções, é muito mais
 *      facil chamar "andarFrente(200)" do que sempre que quiser que o robô ande pra frente ter que configurar as 
 *      velocidades de ambos, e mandar ambos ligarem
 *   
 */
 
#include <AFMotor.h> // Inclui a biblioteca de controle de motores

AF_DCMotor motor1(1, MOTOR12_64KHZ);  // Cria a variável motor1, ligada como motor 1, com 64k pulsos por segundo
AF_DCMotor motor2(2, MOTOR12_64KHZ);  // Cria a variável motor2, ligada como motor 2, com 64k pulsos por segundo

void setup() {
}

void loop() {
  andaFrente(200);  // Roda os dois motores pra frente
  delay(1000);  
  para();  // para de alimentar o motor (sempre recomendado parar antes de mudar de direção)
  delay(100);  
  andaTras(150);  // Roda os dois motores pra frente
  delay(1000);  
  para();  // para de alimentar o motor (sempre recomendado parar antes de mudar de direção)
  delay(100);  
  vira(50, 150);
  delay(1000);
  vira(150, 50);
}

void para()  // Para os dois motores
{
  motor1.run(RELEASE);  
  motor2.run(RELEASE);  
}

void andaFrente(int vel)  // função que faz os dois motores irem pra frente na velocidade passada
{
  if(vel>255) vel=255;  // Corrige os valores das velocidades, caso sejam muito altos ou muito baixos
  if(vel<0) vel=0;

  motor1.setSpeed(vel);  
  motor2.setSpeed(vel);  
  motor1.run(FORWARD);  
  motor2.run(FORWARD);  
}

void andaTras(int vel)
{
  if(vel>255) vel=255;
  if(vel<0) vel=0;

  motor1.setSpeed(vel);  
  motor2.setSpeed(vel);  
  motor1.run(FORWARD);  
  motor2.run(FORWARD);  
}

void vira(int velE, int velD)  // Função que faz virar. Se colocar velocidade maior na velE, vira pra esquerda, e vice versa

{
  if(velE>255) velE=255;
  if(velE<0) velE=0;
  if(velD>255) velD=255;
  if(velD<0) velD=0;

  motor1.setSpeed(velE);  
  motor2.setSpeed(velD);  
  
  motor1.run(FORWARD);  
  motor2.run(FORWARD);  
}
