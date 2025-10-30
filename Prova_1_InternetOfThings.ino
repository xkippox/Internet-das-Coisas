const int LDR = 1;
const int LED_AZUL = 12;
const int LED_VERMELHO = 14;
const int LED_VERDE = 13;

const int BOTAO_1 = 7;
const int BOTAO_2 = 6;

void setup() {

  pinMode(LED_AZUL, OUTPUT); //definindo o LED AZUL como uma saída.
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);

  pinMode(BOTAO_1, INPUT_PULLDOWN);
  pinMode(BOTAO_2, INPUT_PULLDOWN);

  pinMode(LDR, INPUT);
  Serial.begin(9600);

}

int leituraLDR; //criei uma váriavel que vai ler o valor do LDR.
int brilhoLED; // criei uma váriavel que vai converter o bagulho.
bool manual = true;

void loop() {

  leituraLDR = analogRead(LDR); // essa váriavel pega a leitura analogica do Pino LDR.
  brilhoLED = map(leituraLDR, 0, 8191, 0, 255); // faz a transcrição da leitura analogica, pro pino.
  int brilhoOposto = 255 - brilhoLED; // Aqui foi só pra inverter, quanto mais escuro, mais luz, quanto menos, menos luz.
  int contador = 0;

  if(digitalRead(BOTAO_1) == LOW) {

    if(digitalRead(BOTAO_1) == LOW) {
      manual = !manual;
    }

    if(manual = false){

      if (brilhoOposto > 200) {
        digitalWrite(LED_AZUL, HIGH);
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_VERMELHO, LOW);
        Serial.println(brilhoOposto);
        delay(500);
      }


      else if(brilhoOposto < 200 && brilhoOposto > 100) {
        digitalWrite(LED_VERDE, HIGH);
        digitalWrite(LED_AZUL, LOW);
        digitalWrite(LED_VERMELHO, LOW);
        Serial.println(brilhoOposto);
        delay(500);
      }

      else if(brilhoOposto < 100 && brilhoOposto > 1) {
        digitalWrite(LED_VERMELHO, HIGH);
        digitalWrite(LED_AZUL, LOW);
        digitalWrite(LED_VERDE, LOW);
        Serial.println(brilhoOposto);
        delay(500);
      }

      else {
        digitalWrite(LED_VERMELHO, LOW);
        digitalWrite(LED_AZUL, LOW);
        digitalWrite(LED_VERDE, LOW);
        Serial.println(brilhoOposto);
      }

      Serial.println(brilhoOposto);
      delay(500);

    }


    else if(manual = true) {
      if(digitalRead(BOTAO_2) == LOW) {
        contador = contador + 1;

        if(contador = 1){
          digitalWrite(LED_VERMELHO, HIGH);
          digitalWrite(LED_VERDE, LOW);
          digitalWrite(LED_AZUL, LOW);
        }

        if(contador = 2){
          digitalWrite(LED_VERMELHO, HIGH);
          digitalWrite(LED_VERDE, LOW);
          digitalWrite(LED_AZUL, LOW);
        }

        if(contador = 3){
          digitalWrite(LED_VERMELHO, HIGH);
          digitalWrite(LED_VERDE, LOW);
          digitalWrite(LED_AZUL, LOW);
        }
        if(contador = 4){
          contador = 0;
        }


      }

    }

  }

}