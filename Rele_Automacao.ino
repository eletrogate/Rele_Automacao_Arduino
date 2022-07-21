#define LeituraSensorDeSom 8
#define AcionaRelay 7

int AjusteSensorDeSom = A0;
int leitura = 0;
int ultimaleitura = 0;
int Analog;
int Estado = HIGH;

void setup(){
  Serial.begin(9600);
  pinMode(LeituraSensorDeSom, INPUT);
  pinMode(AcionaRelay, OUTPUT);
  pinMode(13, OUTPUT);
  delay(100);
}

void loop(){
  leitura = digitalRead(LeituraSensorDeSom);
  if (leitura != ultimaleitura){
    ultimaleitura = leitura;
    Serial.println(leitura);
    delay(250);

    if (leitura == HIGH){
      digitalWrite(13, Estado);
      digitalWrite(AcionaRelay, Estado);
      Estado = !Estado;
    }
  }
  delay(1);
}