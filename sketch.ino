const int pinSensorUmidade = A0;
const int pinPotenciometro = A1;
const int pinLedVerde      = 8;
const int pinLedVermelho   = 9;

const int RS = 12, EN = 11, D4 = 5, D5 = 4, D6 = 3, D7 = 2;

void lcdPulse() {
  digitalWrite(EN, HIGH);
  delayMicroseconds(1);
  digitalWrite(EN, LOW);
  delayMicroseconds(100);
}

void lcdEnviar4bits(byte val) {
  digitalWrite(D4, (val >> 0) & 1);
  digitalWrite(D5, (val >> 1) & 1);
  digitalWrite(D6, (val >> 2) & 1);
  digitalWrite(D7, (val >> 3) & 1);
  lcdPulse();
}

void lcdEnviar(byte val, bool cmd) {
  digitalWrite(RS, cmd ? HIGH : LOW);
  lcdEnviar4bits(val >> 4);
  lcdEnviar4bits(val & 0x0F);
  delayMicroseconds(150);
}

void lcdCmd(byte c)  { lcdEnviar(c, false); }
void lcdChar(char c) { lcdEnviar(c, true);  }

void lcdInit() {
  delay(50);
  digitalWrite(RS, LOW);
  digitalWrite(EN, LOW);
  lcdEnviar4bits(0x03); delay(5);
  lcdEnviar4bits(0x03); delayMicroseconds(150);
  lcdEnviar4bits(0x03);
  lcdEnviar4bits(0x02);
  lcdCmd(0x28);
  lcdCmd(0x0C);
  lcdCmd(0x06);
  lcdCmd(0x01);
  delay(2);
}

void lcdPos(byte col, byte row) {
  lcdCmd(0x80 | (col + (row == 1 ? 0x40 : 0x00)));
}

void lcdStr(const char* s) {
  while (*s) lcdChar(*s++);
}

void lcdInt(int n) {
  if (n >= 100) lcdChar('0' + n / 100);
  if (n >= 10)  lcdChar('0' + (n / 10) % 10);
  lcdChar('0' + n % 10);
}

void ligarLed(int pino)    { digitalWrite(pino, HIGH); }
void desligarLed(int pino) { digitalWrite(pino, LOW);  }

void setup() {
  pinMode(pinLedVerde,    OUTPUT);
  pinMode(pinLedVermelho, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);

  desligarLed(pinLedVerde);
  desligarLed(pinLedVermelho);

  lcdInit();
  lcdPos(0, 0); lcdStr("  Smart Garden  ");
  lcdPos(0, 1); lcdStr("Inicializando...");
  delay(1500);
}

void loop() {
  int leituraUmidade = analogRead(pinSensorUmidade);
  int leituraPot     = analogRead(pinPotenciometro);

  int umidade = map(leituraUmidade, 1023, 0, 0, 100);
  umidade = constrain(umidade, 0, 100);

  int limite = map(leituraPot, 0, 1023, 0, 100);
  limite = constrain(limite, 0, 100);

  bool regar = umidade < limite;

  if (regar) {
    ligarLed(pinLedVermelho);
    desligarLed(pinLedVerde);
  } else {
    ligarLed(pinLedVerde);
    desligarLed(pinLedVermelho);
  }

  lcdCmd(0x01);
  delay(2);

  lcdPos(0, 0);
  lcdStr("Umid:");
  lcdInt(umidade);
  lcdChar('%');
  lcdPos(9, 0);
  lcdStr("Lim:");
  lcdInt(limite);
  lcdChar('%');

  lcdPos(0, 1);
  lcdStr(regar ? "Regar: SIM      " : "Regar: NAO      ");

  delay(500);
}
