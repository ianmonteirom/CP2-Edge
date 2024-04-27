// Adicionando as bibliotecas para o Display e o DHT
#include <LiquidCrystal.h>
#include <DHT.h>

// Definindo o pino do DHT, o tipo do DHT, o número de leituras para o cálculo da média e os pinos dos LEDs
#define DHTPIN 7     // Pino de dados do DHT22 conectado ao pino digital 7
#define DHTTYPE DHT11   // Tipo do sensor DHT
#define LDRPIN A0 // Defino o pino A0 para o LDR
#define NUM_READINGS 10  // Número de leituras para calcular a média
#define LEDG 13 // Define o pino 13 digital para o led VERDE
#define LEDY 8 // Define o pino 8 digital para o led AMARELO
#define LEDR 6 // Define o pino 6 digital para o led VERMELHO
#define BUZZER 9 // Define o pino digital 9 para a buzina
#define DELAY_PADRAO 5000 // Define o delay padrão para 5 segundos

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

// Definindo os bytes do desenho do logo
byte logo0x3[] = { B00000, B00011, B00100, B01000, B01000, B10000, B10000, B10000 };
byte logo0x4[] = { B11111, B00000, B11100, B10010, B10010, B10010, B10010, B11100 };
byte logo0x5[] = { B00000, B11000, B00100, B00010, B00010, B00001, B00001, B00001 };
byte logo1x3[] = { B10000, B10000, B01000, B01000, B00100, B00011, B00000, B00000 };
byte logo1x4[] = { B01111, B01000, B01111, B00001, B01111, B00000, B11111, B00000 };
byte logo1x5[] = { B00001, B00001, B00010, B00010, B00100, B11000, B00000, B00000 };

// Desenho da lua (luminosidade ok)
byte lua8x0[] = { B00000, B00000, B00000, B00001, B00111, B01110, B01110, B11110 };
byte lua9x0[] = { B00000, B00000, B00000, B10000, B00000, B00000, B00000, B00000 };
byte lua8x1[] = { B11110, B01110, B01110, B00111, B00011, B00000, B00000, B00000 };
byte lua9x1[] = { B00000, B00000, B00001, B11110, B11100, B00000, B00000, B00000 };

// Desenho do sol (luminosidade meia-luz)
byte solm9x0[] = { B00000, B00000, B10000, B01000, B00011, B00111, B01111, B01111 };
byte solm10x0[] = { B00000, B00000, B00001, B00010, B11000, B11100, B11110, B11110 };
byte solm9x1[] = { B01111, B01111, B00111, B00011, B01000, B10000, B00000, B00000 };
byte solm10x1[] = { B11110, B11110, B11100, B11000, B00010, B00001, B00000, B00000 };

// Desenho do sol escaldante (luminosidade alta)
byte sol7x0[] = { B00000, B00000, B00000, B00000, B00010, B00001, B00000, B00011 };
byte sol8x0[] = { B00000, B01000, B00100, B00000, B00011, B00111, B01111, B01111 };
byte sol9x0[] = { B00000, B00010, B00100, B00000, B11000, B11100, B11110, B11110 };
byte sol10x0[] = { B00000, B00000, B00000, B00000, B01000, B10000, B00000, B11000 };
byte sol7x1[] = { B00000, B00001, B00010, B00000, B00000, B00000, B00000, B00000 };
byte sol8x1[] = { B01111, B01111, B00111, B00011, B00000, B00100, B01000, B00000 };
byte sol9x1[] = { B11110, B11110, B11100, B11000, B00000, B00100, B00010, B00000 };
byte sol10x1[] = { B00000, B00000, B10000, B01000, B00000, B00000, B00000, B00000 };

// Desenho da nuvem seca (umidade baixa)
byte nuvems8x0[] = { B00000, B00000, B00000, B00110, B01001, B10000, B11111, B00100 };
byte nuvems9x0[] = { B00000, B00000, B00000, B11000, B00100, B00010, B11111, B10000 };
byte nuvems8x1[] = { B01001, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };
byte nuvems9x1[] = { B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000 };

// Desenho da nuvem meio cheia (umidade ok)
byte nuvemmc8x0[] = { B00000, B00000, B00000, B00110, B01001, B10000, B11111, B00100 };
byte nuvemmc9x0[] = { B00000, B00000, B00000, B11000, B00100, B00010, B11111, B10000 };
byte nuvemmc8x1[] = { B00000, B01001, B10010, B00000, B00000, B00000, B00000, B00000 };
byte nuvemmc9x1[] = { B00100, B01000, B00000, B00000, B00000, B00000, B00000, B00000 };

// Desenho da nuvem cheia (umidade alta)
byte nuvemc8x0[] = { B00000, B00000, B00000, B00110, B01001, B10000, B11111, B00100 };
byte nuvemc9x0[] = { B00000, B00000, B00000, B11000, B00100, B00010, B11111, B10100 };
byte nuvemc8x1[] = { B01001, B10010, B00000, B00101, B01000, B00000, B00100, B00000 };
byte nuvemc9x1[] = { B01000, B00000, B10000, B00100, B01000, B00000, B00000, B00000 };

// Desenho do termômetro vazio (temperatura baixa)
byte term8x0[] = { B00001, B00010, B00011, B00011, B00010, B00011, B00010, B00011 };
byte term9x0[] = { B10000, B01000, B01000, B01000, B01000, B01000, B01000, B01000 };
byte term8x1[] = { B00010, B00100, B01000, B01011, B01001, B00100, B00011, B00000 };
byte term9x1[] = { B01000, B00100, B00010, B11010, B10010, B00100, B11000, B00000 };

// Desenho do termômetro meio cheio (temperatura ok)
byte termm8x0[] = { B00000, B00001, B00010, B00011, B00010, B00011, B00010, B00011 };
byte termm9x0[] = { B00000, B10000, B01000, B01000, B01000, B01000, B01000, B01000 };
byte termm8x1[] = { B00011, B00101, B01011, B01011, B01001, B00100, B00011, B00000 };
byte termm9x1[] = { B11000, B10100, B11010, B11010, B10010, B00100, B11000, B00000 };

// Desenho do termômetro cheio (temperatura alta)
byte termc8x0[] = { B00001, B00010, B00011, B00011, B00010, B00011, B00010, B00011 };
byte termc9x0[] = { B10000, B11000, B11000, B11000, B11000, B11000, B11000, B11000 };
byte termc8x1[] = { B00011, B00101, B01011, B01011, B01001, B00100, B00011, B00000 };
byte termc9x1[] = { B11000, B10100, B11010, B11010, B10010, B00100, B11000, B00000 };

// Desenho da nuvem (umidade)
byte nuvem7x0[] = { B00000, B00000, B00000, B00000, B00000, B00000, B00001, B00000 };
byte nuvem8x0[] = { B00000, B00000, B00000, B00110, B01001, B10000, B11111, B00100 };
byte nuvem9x0[] = { B00000, B00000, B00000, B11000, B00100, B00010, B11111, B10000 };
byte nuvem8x1[] = { B01001, B10010, B00000, B00010, B00100, B00000, B00000, B00000 };
byte nuvem9x1[] = { B01000, B10000, B00100, B01000, B00000, B00000, B00000, B00000 };



void setup()
{
  // Iniciando o serial
  Serial.begin(9600);
  Serial.println("D A T A   S P H E R E");

  // Definindo os pinos dos leds como SAÍDA
  pinMode(LDRPIN, INPUT);  // Define o pino LDRPIN como saída
  pinMode(LEDG, OUTPUT);   // Define o pino LEDG como saída
  pinMode(LEDY, OUTPUT);   // Define o pino LEDY como saída
  pinMode(LEDR, OUTPUT);   // Define o pino LEDR como saída
  pinMode(BUZZER, OUTPUT); // Define o pino BUZZER como saída

  // Iniciando o DHT e o Display 16 x 2
  dht.begin();
  lcd.begin(16,2); 

  // Criando os caracteres para o desenho do logo para o display              
  lcd.createChar(0, logo0x3);
  lcd.createChar(1, logo0x4);
  lcd.createChar(2, logo0x5);
  lcd.createChar(3, logo1x3);
  lcd.createChar(4, logo1x4);
  lcd.createChar(5, logo1x5);

  // Mostrando o LOGO no Display
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.write(byte(0));
  lcd.setCursor(4, 0);
  lcd.write(byte(1));
  lcd.setCursor(5, 0);
  lcd.write(byte(2));
  lcd.setCursor(3, 1);
  lcd.write(byte(3));
  lcd.setCursor(4, 1);
  lcd.write(byte(4));
  lcd.setCursor(5, 1);
  lcd.write(byte(5));

  lcd.setCursor(7, 0);
  lcd.print("DATA");
  lcd.setCursor(8, 1);
  lcd.print("SPHERE");


  // Delay para o logo da empresa aparecer no display por 5 segundos
  delay(DELAY_PADRAO);
}

void loop() {

  // Definindo o valor da umidade e temperatura
  float humidity = 0;
  float temperature = 0;
  float luminosityLux = 0;
  
  // Realizando X leituras e calculando a média da umidade e temperatura
  for (int i = 0; i < NUM_READINGS; i++) {
  humidity += dht.readHumidity();          // Soma as leituras de umidade
  temperature += dht.readTemperature();    // Soma as leituras de temperatura
  luminosityLux += analogRead(LDRPIN);     // Soma as leituras da luminosidade
  }

  // Calcula a média das leituras
  luminosityLux /= NUM_READINGS;
  humidity /= NUM_READINGS;
  temperature /= NUM_READINGS;

  // Convertendo a Luminosidade
  float luminosity = map(luminosityLux, 1023, 0, 0, 100);

  // Convertendo o valores da luminosidade, umidade e temperatura para int, para não aparecer casas decimais no display
  int luminosityInt = static_cast<int>(luminosity);
  int humidityInt = static_cast<int>(humidity);
  int temperatureInt = static_cast<int>(temperature);

 // Escrevendo Luminosidade no display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Lumi.");

  // Verifica o valor da média da LUMINOSIDADE e mostra no serial e no display
if (luminosity <= 15) {
    // Faça algo se a luminosidade for baixa
    // Desliga os outros LEDs e liga o verde, indicando luminosidade baixa (ok)
    digitalWrite(LEDG, HIGH); // Liga o LED verde
    digitalWrite(LEDY, LOW);  // Desliga o LED amarelo
    digitalWrite(LEDR, LOW);  // Desliga o LED vermelho

    Serial.print("Luminosidade ESCURA: ");

    // Escreve no display no estado da umidade
    lcd.setCursor(0, 1);
    lcd.print("OK");

    // Criando os caracteres para o desenho da lua para o display
    lcd.createChar(0, lua8x0);
    lcd.createChar(1, lua9x0);
    lcd.createChar(2, lua8x1);
    lcd.createChar(3, lua9x1);

    // Mostrando a lua no display
    lcd.setCursor(8, 0);
    lcd.write(byte(0));
    lcd.setCursor(9, 0);
    lcd.write(byte(1));
    lcd.setCursor(8, 1);
    lcd.write(byte(2));
    lcd.setCursor(9, 1);
    lcd.write(byte(3));

} else if (luminosity > 15 && luminosity <= 50) {
    // Faça algo se a luminosidade estiver moderada
    // Desliga os outros LEDs e liga o amarelo, indicando luminosidade moderada (alerta)
    digitalWrite(LEDG, LOW); // Desliga o LED verde
    digitalWrite(LEDY, HIGH);  // Liga o LED amarelo
    digitalWrite(LEDR, LOW);  // Desliga o LED vermelho

    Serial.print("Luminosidade MODERADA: ");

    // Escreve no display no estado da umidade
    lcd.setCursor(0, 1);
    lcd.print("MEIA-LUZ");

    // Criando os caracteres para o desenho do sol para o display

    lcd.createChar(0, solm9x0);
    lcd.createChar(1, solm10x0);
    lcd.createChar(2, solm9x1);
    lcd.createChar(3, solm10x1);

    // Mostrando a lua no display
    lcd.setCursor(9, 0);
    lcd.write(byte(0));
    lcd.setCursor(10, 0);
    lcd.write(byte(1));
    lcd.setCursor(9, 1);
    lcd.write(byte(2));
    lcd.setCursor(10, 1);
    lcd.write(byte(3));

} else {
    // Faça algo se a luminosidade estiver alta
    // Desliga os outros LEDs e liga o vermelho, indicando luminosidade alta (estado crítico)
    digitalWrite(LEDG, LOW); // Desliga o LED verde
    digitalWrite(LEDY, LOW);  // Desliga o LED amarelo
    digitalWrite(LEDR, HIGH);  // Liga o LED vermelho

    tone(BUZZER, 2000, 5000); // Dispara a buzina a uma frequência DE 2000Hz por 5 segundos

    Serial.print("Luminosidade ALTA: ");

    // Escreve no display no estado da umidade
    lcd.setCursor(0, 1);
    lcd.print("ALTA");

    // Criando os caracteres para o desenho do sol para o display
    lcd.createChar(0, sol7x0);
    lcd.createChar(1, sol8x0);
    lcd.createChar(2, sol9x0);
    lcd.createChar(3, sol10x0);
    lcd.createChar(4, sol7x1);
    lcd.createChar(5, sol8x1);
    lcd.createChar(6, sol9x1);
    lcd.createChar(7, sol10x1);

    // Mostrando o sol no display
    lcd.setCursor(7, 0);
    lcd.write(byte(0));
    lcd.setCursor(8, 0);
    lcd.write(byte(1));
    lcd.setCursor(9, 0);
    lcd.write(byte(2));
    lcd.setCursor(10, 0);
    lcd.write(byte(3));
    lcd.setCursor(7, 1);
    lcd.write(byte(4));
    lcd.setCursor(8, 1);
    lcd.write(byte(5));
    lcd.setCursor(9, 1);
    lcd.write(byte(6));
    lcd.setCursor(10, 1);
    lcd.write(byte(7));

}

  // Mostra a porcentagem de luminosidade no Serial e no Display
  Serial.print(luminosity);
  Serial.println(" %\t");
  lcd.setCursor(13,0);
  lcd.print(luminosityInt);
  lcd.setCursor(15, 0);
  lcd.print("%");

delay(DELAY_PADRAO);

  // Escrevendo Umidade no display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Umid.");

  // Verifica o valor da média da UMIDADE e mostra no serial e no display
  // Se a umidade estiver abaixo de 50%
  if (humidity < 50) {

    // Desliga os outros LEDs e liga o vermelho, indicando estado crítico
    digitalWrite(LEDG, LOW); // Desliga o LED verde
    digitalWrite(LEDY, LOW);  // Desliga o LED amarelo
    digitalWrite(LEDR, HIGH);  // Liga o LED vermelho

    tone(BUZZER, 2000, 5000); // Dispara a buzina a uma frequência DE 2000Hz por 5 segundos

    Serial.print("Umidade BAIXA: ");

    // Escreve no display no estado da umidade
    lcd.setCursor(0, 1);
    lcd.print("BAIXA");

    // Criando os caracteres para o desenho da nuvem seca para o display
    lcd.createChar(0, nuvems8x0);
    lcd.createChar(1, nuvems9x0);
    lcd.createChar(2, nuvems8x1);
    lcd.createChar(3, nuvems9x1);

    // Mostrando a nuvem seca no display
    lcd.setCursor(8, 0);
    lcd.write(byte(0));
    lcd.setCursor(9, 0);
    lcd.write(byte(1));
    lcd.setCursor(8, 1);
    lcd.write(byte(2));
    lcd.setCursor(9, 1);
    lcd.write(byte(3));
   

  // Se a umidade estiver entre 50% e 70%
  } else if (humidity >= 50 && humidity <= 70) {

    // Desliga os outros LEDs e liga o verde, indicando que está OK
    digitalWrite(LEDG, HIGH); // Liga o LED verde
    digitalWrite(LEDY, LOW);  // Desliga o LED amarelo
    digitalWrite(LEDR, LOW);  // Desliga o LED vermelho

    Serial.print("Umidade OK: ");

    // Escreve no display no estado da umidade
    lcd.setCursor(0, 1);
    lcd.print("OK");

    // Criando os caracteres para o desenho da nuvem meio cheia para o display
    lcd.createChar(0, nuvemmc8x0);
    lcd.createChar(1, nuvemmc9x0);
    lcd.createChar(2, nuvemmc8x1);
    lcd.createChar(3, nuvemmc9x1);

    // Mostrando a nuvem meio cheia no display
    lcd.setCursor(8, 0);
    lcd.write(byte(0));
    lcd.setCursor(9, 0);
    lcd.write(byte(1));
    lcd.setCursor(8, 1);
    lcd.write(byte(2));
    lcd.setCursor(9, 1);
    lcd.write(byte(3));

  // Se a umidade estiver acima de 70%
  } else if (humidity > 70) {

    // Desliga os outros LEDs e liga o vermelho, indicando estado crítico
    digitalWrite(LEDG, LOW); // Desliga o LED verde
    digitalWrite(LEDY, LOW);  // Desliga o LED amarelo
    digitalWrite(LEDR, HIGH);  // Liga o LED vermelho

    tone(BUZZER, 2000, 5000); // Dispara a buzina a uma frequência DE 2000Hz por 5 segundos

    Serial.print("Umidade ALTA: ");

    // Escreve no display no estado da umidade
    lcd.setCursor(0, 1);
    lcd.print("ALTA");

    // Criando os caracteres para o desenho da nuvem cheia para o display
    lcd.createChar(0, nuvemc8x0);
    lcd.createChar(1, nuvemc9x0);
    lcd.createChar(2, nuvemc8x1);
    lcd.createChar(3, nuvemc9x1);

    // Mostrando a nuvem cheia no display
    lcd.setCursor(8, 0);
    lcd.write(byte(0));
    lcd.setCursor(9, 0);
    lcd.write(byte(1));
    lcd.setCursor(8, 1);
    lcd.write(byte(2));
    lcd.setCursor(9, 1);
    lcd.write(byte(3));

  }

  // Mostra a porcentagem de umidade no Serial e no Display
  Serial.print(humidity);
  Serial.println(" %\t");
  lcd.setCursor(13,0);
  lcd.print(humidityInt);
  lcd.setCursor(15, 0);
  lcd.print("%");

  // Delay para mostrar a umidade no display por 5 segundos
  delay(DELAY_PADRAO);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp.");

  // Verifica o valor da média da TEMPERATURA e mostra no serial e no display
  if (temperature < 10) {

    // Desliga os outros LEDs e liga o amarelo, indicando estado de alerta
    digitalWrite(LEDG, LOW); // Desliga o LED verde
    digitalWrite(LEDY, HIGH);  // Liga o LED amarelo
    digitalWrite(LEDR, LOW);  // Desliga o LED vermelho

    tone(BUZZER, 1500, 5000); // Dispara a buzina a uma frequência DE 1500Hz por 5 segundos

    Serial.print("Temperatura BAIXA: ");

    // Escreve no display no estado da temperatura
    lcd.setCursor(0, 1);
    lcd.print("BAIXA");

    // Criando os caracteres para o desenho do termômetro vazio para o display
    lcd.createChar(0, term8x0);
    lcd.createChar(1, term9x0);
    lcd.createChar(2, term8x1);
    lcd.createChar(3, term9x1);

    // Mostrando o termômetro vazio na tela
    lcd.setCursor(8, 0);
    lcd.write(byte(0));
    lcd.setCursor(9, 0);
    lcd.write(byte(1));
    lcd.setCursor(8, 1);
    lcd.write(byte(2));
    lcd.setCursor(9, 1);
    lcd.write(byte(3));


  } else if (temperature >= 10 && temperature <= 15) {

    // Desliga os outros LEDs e liga o verde, indicando que está OK
    digitalWrite(LEDG, HIGH); // Liga o LED verde
    digitalWrite(LEDY, LOW);  // Desliga o LED amarelo
    digitalWrite(LEDR, LOW);  // Desliga o LED vermelho

    Serial.print("Temperatura OK: ");

    // Escreve no display no estado da temperatura
    lcd.setCursor(0, 1);
    lcd.print("OK");

    // Criando os caracteres para o desenho do termômetro meio cheio para o display
    lcd.createChar(0, termm8x0);
    lcd.createChar(1, termm9x0);
    lcd.createChar(2, termm8x1);
    lcd.createChar(3, termm9x1);

    // Mostrando a lua no display
    lcd.setCursor(8, 0);
    lcd.write(byte(0));
    lcd.setCursor(9, 0);
    lcd.write(byte(1));
    lcd.setCursor(8, 1);
    lcd.write(byte(2));
    lcd.setCursor(9, 1);
    lcd.write(byte(3));

  } else if (temperature > 15) {

    // Desliga os outros LEDs e liga o amarelo, indicando estado de alerta
    digitalWrite(LEDG, LOW); // Desliga o LED verde
    digitalWrite(LEDY, HIGH);  // Liga o LED amarelo
    digitalWrite(LEDR, LOW);  // Desliga o LED vermelho

    tone(BUZZER, 1500, 5000); // Dispara a buzina a uma frequência DE 1500Hz por 5 segundos

    Serial.print("Temperatura ALTA: ");

    // Escreve no display no estado da temperatura
    lcd.setCursor(0, 1);
    lcd.print("ALTA");

    // Criando os caracteres para o desenho do termômetro cheio para o display
    lcd.createChar(0, termc8x0);
    lcd.createChar(1, termc9x0);
    lcd.createChar(2, termc8x1);
    lcd.createChar(3, termc9x1);

    // Mostrando o termômetro vazio na tela
    lcd.setCursor(8, 0);
    lcd.write(byte(0));
    lcd.setCursor(9, 0);
    lcd.write(byte(1));
    lcd.setCursor(8, 1);
    lcd.write(byte(2));
    lcd.setCursor(9, 1);
    lcd.write(byte(3));

  }

  // Mostra a temperatura em graus celsius no Serial e no Display
  Serial.print(temperature);
  Serial.println(" °C");
  lcd.setCursor(13,0);
  lcd.print(temperatureInt);
  lcd.setCursor(15, 0);
  lcd.print("C");

  // Delay para mostrar a temperatura no display por 5 segundos
  delay(DELAY_PADRAO);

}
