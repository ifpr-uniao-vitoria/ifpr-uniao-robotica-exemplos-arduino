/*
 *  Esse exemplo mostra como controlar um motor utilizando o motor shield L293D e a biblioteca AFMotor
 *  
 *  Ligações:
 *  Motor Shield L293D instalado em cima do Arduino UNO
 *  Motor ligado no slot M1 do Shield
 *  Alimentação fornecida pelo próprio Arduino ou Bateria Externa
 *  Se alimentado por bateria externa, verificar a voltagem da bateria para não queimar o arduino (entre 6v e 12v).
 *  
 *  Notas:
 *  1 - você pode alimentar o arduino e os motores com a mesma bateria - para isso, você deve deixar um Jumper ligado na posição "PWRJMP" do Motor Shield, e ligue a bateria em "EXT-PWR" do Shield;
 *  2 - Se você preferir alimentar o arduino com uma bateria, e os motores com outra, retire o Jumper acima, ligue a bateria dos motores em "EXT-PWR" do Shield, 
 *      e a Bateria do Arduino com um conector de energia no próprio arduino;
 *  3 - Quando utilizar bateria, recomenda-se a utilização de um regulador de voltagem, especialmente quando os motores não suportarem a voltagem da bateria utilizada -
 *      Exemplo, motor de 6v, bateria de 11,1v - regular (com o parafuso do regulador) para aproximadamente 6v, medindo com o multimetro;
 *      Baterias acima de 12v podem danificar o Arduino, e o Motor Shield não faz essa regulagem. Nesse caso, usar regulador externo também;
 *  4 - Recomenda-se, para facilitar a manutenção dos robôs, manter a consistência na cor dos Jumpers - exemplo, vermelho para negativo, verde para positivo, outras cores para demais sinais;
 *  5 - Recomenda-se colocar uma chave liga/desliga entre a bateria e o shield (no pino do positivo), para não precisar ficar "arrancando" a bateria do robô para ele parar
 *  6 - Vários dos jumpers vermelhos do campus vieram com defeito - se você ligou tudo certo mas algo não está funcionando como deveria, lembre de verificar os jumpers.
 *  7 - Apesar das proteções que o arduino possui, recomenda-se desligar a bateria ao programar o arduino, além das recomendações básicas do trabalho com eletricidade - cuidado ao encostar nos
 *      componentes, manter as peças em superficies não condutoras, cuidar com as ligações a fim de evitar curto-circuitos
 *  8 - Baterias LIPO são bem potentes, mas demandam cuidados específicos - só carregar dentro do saco anti-chamas, evitar descarregar demais para não perder qualidade, cuidar com 
 *      curto-circuitos, carregar apenas com o carregador correto, não deixar tempo demais no carregador - baterias LIPO podem explodir ou pegar fogo se mal-cuidadas      
 *  9 - Repare na diferença de velocidade/força do motor rodando em alimentação USB, em uma bateria bem carregada e em uma bateria mal carregada - isso pode fazer diferença em uma competição
 *  
 *  Imagens:
 *  01-basico.jpg - ligação básica, alimentada pela USB apenas (poderia ser usado um powerbank, por exemplo)
 *  01-basico+bateria.jpg - ligação básica, com alimentação por bateria LIPO, sem regulador
 *   
 */
 
#include <AFMotor.h> // Inclui a biblioteca de controle de motores

AF_DCMotor motor(1, MOTOR12_64KHZ);  // Cria a variável motor, ligada como motor 1, com 64k pulsos por segundo

void setup() {
}

void loop() {
  motor.setSpeed(200);  // define a velocidade do motor. Pode ser mudada durante o decorrer do programa - 255 = 100%. Não é linear
  motor.run(FORWARD);  // motor para frente na velocidade configurada
  delay(1000);  
  motor.run(RELEASE);  // para de alimentar o motor (sempre recomendado parar antes de mudar de direção)
  delay(100);  
  motor.setSpeed(100);  // muda o motor para uma velocidade mais lenta
  motor.run(BACKWARD);  // motor para trás na velocidade configurada  
  delay(1000);  
}
