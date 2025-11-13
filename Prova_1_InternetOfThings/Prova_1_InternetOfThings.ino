
// Definindo as constantes e seus nomes.
const int LDR = 1;
const int LED_AZUL = 12;
const int LED_VERDE = 13;
const int LED_VERMELHO = 14;
const int BOTAO_MODO = 2;
const int BOTAO_CORES = 3;


void setup() {

  // Definindo as entradas e saídas.
  pinMode(LDR, INPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BOTAO_MODO, INPUT_PULLUP);
  pinMode(BOTAO_CORES, INPUT_PULLUP);
  Serial.begin(9600);

}

int leituraLDR;
int ldrConvertido;
bool manual = false;
int contador = 1;

void loop() {

  leituraLDR = analogRead(LDR);
  ldrConvertido = map(leituraLDR, 0, 8191, 0, 255);
  Serial.println(leituraLDR);
  Serial.println(ldrConvertido);

  if (digitalRead(BOTAO_MODO) == LOW) {
    manual = !manual;
    Serial.println(manual);
    delay(250);
  }

  if (!manual) {
    Serial.println("Modo Automatico");

    if(ldrConvertido > 200) {

      digitalWrite(LED_AZUL, HIGH);
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(LED_VERDE, LOW);
      Serial.println("LED AZUL LIGADO!");

    } 
    else if (ldrConvertido < 200 && ldrConvertido > 100) {

      digitalWrite(LED_VERMELHO, HIGH);
      digitalWrite(LED_AZUL, LOW);
      digitalWrite(LED_VERDE, LOW);
      Serial.println("LED VERMELHO LIGADO!");

    } 
    else if (ldrConvertido < 100 && ldrConvertido > 1 ) {

      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(LED_AZUL, LOW);
      Serial.println("LED VERDE LIGADO!");

    }

  } else { 
    Serial.println("Modo Manual!");

    if (digitalRead(BOTAO_CORES) == LOW) {
      contador++;
      delay(250);
    }

    if (contador == 4) {
      contador = 1;
    }

    if (contador == 1) {
      digitalWrite(LED_VERMELHO, HIGH);
      digitalWrite(LED_AZUL, LOW);
      digitalWrite(LED_VERDE, LOW);
      Serial.println("Led Vermelho ligado!");
    }
    else if (contador == 2) {
      digitalWrite(LED_AZUL, HIGH);
      digitalWrite(LED_VERMELHO, LOW);
      digitalWrite(LED_VERDE, LOW);
      Serial.println("Led Azul ligado!");
    }
    else if (contador == 3) {
      digitalWrite(LED_VERDE, HIGH);
      digitalWrite(LED_AZUL, LOW);
      digitalWrite(LED_AZUL, LOW);
      Serial.println("Led Verde ligado!");
    }

    
  
  }

 
}
