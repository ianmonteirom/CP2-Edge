// Adicionando as bibliotecas para o Display e o DHT
#include <LiquidCrystal.h>
#include <DHT.h>

// Definindo o pino do DHT, o tipo do DHT, o número de leituras para o cálculo da média e os pinos dos LEDs
#define DHTPIN 7     // Pino de dados do DHT22 conectado ao pino digital 7
#define DHTTYPE DHT22   // Tipo do sensor DHT
#define NUM_READINGS 10  // Número de leituras para calcular a média
#define LEDG 13 // Define o pino 13 digital para o led VERDE
#define LEDY 8 // Define o pino 8 digital para o led AMARELO
#define LEDR 6 // Define o pino 6 digital para o led VERMELHO
#define BUZZER 9 // Define o pino digital 9 para a buzina
#define DELAY_PADRAO 5000 // Define o delay padrão para 5 segundos

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

// Definindo os desenhos que aparecerão no display
byte bateria0[] = { B00000, B11111, B10000, B10000, B10000, B10000, B11111, B00000 };
byte bateria1[] = { B00000, B11111, B00000, B00000, B00000, B00000, B11111, B00000 };
byte bateria2[] = { B00000, B11100, B00110, B00110, B00110, B00110, B11100, B00000 };

void setup()
{
  // Iniciando o serial
  Serial.begin(9600);
  Serial.println("D A T A   S P H E R E");

  // Definindo os pinos dos leds como SAÍDA
  pinMode(LEDG, OUTPUT);   // Define o pino LEDG como saída
  pinMode(LEDY, OUTPUT);   // Define o pino LEDY como saída
  pinMode(LEDR, OUTPUT);   // Define o pino LEDR como saída
  pinMode(BUZZER, OUTPUT); // Define o pino BUZZER como saída

  // Iniciando o DHT e o Display 16 x 2
  dht.begin();
  lcd.begin(16,2); 

  // Criando os caracteres para os desenhos que aparecerão no display
  lcd.clear();                  
  lcd.createChar(0, bateria0);
  lcd.createChar(1, bateria1);
  lcd.createChar(2, bateria2);

  // Mostrando o LOGO no Display
  lcd.setCursor(0, 0);
  lcd.print("D A T A");
  lcd.setCursor(0, 1);
  lcd.print("S P H E R E");

  // Delay para o logo da empresa aparecer no display por 5 segundos
  delay(DELAY_PADRAO);
}

void loop() {

  // Definindo o valor da umidade e temperatura
  float humidity = 0;
  float temperature = 0;
  
  // Realizando X leituras e calculando a média da umidade e temperatura
  for (int i = 0; i < NUM_READINGS; i++) {

    humidity += dht.readHumidity();    // Soma as leituras de umidade
    temperature += dht.readTemperature(); // Soma as leituras de temperatura
  }

  // Calcula a média das leituras
  humidity /= NUM_READINGS;
  temperature /= NUM_READINGS;

  // Convertendo o valores da umidade e temperatura para int, para não aparecer casas decimais no display
  int humidityInt = static_cast<int>(humidity);
  int temperatureInt = static_cast<int>(temperature);

  // Escrevendo Umidade no display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Umidade");

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
  lcd.print("Temperatura");

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
  } else if (temperature >= 10 && temperature <= 15) {

    // Desliga os outros LEDs e liga o verde, indicando que está OK
    digitalWrite(LEDG, HIGH); // Liga o LED verde
    digitalWrite(LEDY, LOW);  // Desliga o LED amarelo
    digitalWrite(LEDR, LOW);  // Desliga o LED vermelho

    Serial.print("Temperatura OK: ");

    // Escreve no display no estado da temperatura
    lcd.setCursor(0, 1);
    lcd.print("OK");
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


  /* 
  Desenho da Bateria VAZIA no display
  lcd.setCursor(13, 1);
  lcd.write(byte(0));
  lcd.setCursor(14, 1);
  lcd.write(byte(1));
  lcd.setCursor(15, 1);
  lcd.write(byte(2));
  */
}
