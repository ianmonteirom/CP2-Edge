// Adicionando as bibliotecas para o Display e o DHT
#include <LiquidCrystal.h>
#include <DHT.h>

// Definindo o pino do DHT, o tipo do DHT e o número de leituras para o cálculo da média
#define DHTPIN 7     // Pino de dados do DHT22 conectado ao pino digital 7
#define DHTTYPE DHT22   // Tipo do sensor DHT
#define NUM_READINGS 5  // Número de leituras para calcular a média

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
  if (humidity < 50) {
    Serial.print("Umidade BAIXA: ");
    lcd.setCursor(0, 1);
    lcd.print("BAIXA");
  } else if (humidity >= 50 && humidity <= 70) {
    Serial.print("Umidade OK: ");
    lcd.setCursor(0, 1);
    lcd.print("OK");
  } else if (humidity > 70) {
    Serial.print("Umidade ALTA: ");
    lcd.setCursor(0, 1);
    lcd.print("ALTA");
  }
  Serial.print(humidity);
  Serial.println(" %\t");
  lcd.setCursor(13,0);
  lcd.print(humidityInt);
  lcd.setCursor(15, 0);
  lcd.print("%");
  
  // 
  delay(NUM_READINGS * 1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperatura");

  // Verifica o valor da média da TEMPERATURA e mostra no serial e no display
  if (temperature < 10) {
    Serial.print("Temperatura BAIXA: ");
    lcd.setCursor(0, 1);
    lcd.print("BAIXA");
  } else if (temperature >= 10 && temperature <= 15) {
    Serial.print("Temperatura OK: ");
    lcd.setCursor(0, 1);
    lcd.print("OK");
  } else if (temperature > 15) {
    Serial.print("Temperatura ALTA: ");
    lcd.setCursor(0, 1);
    lcd.print("ALTA");
  }
  Serial.print(temperature);
  Serial.println(" °C");
  lcd.setCursor(13,0);
  lcd.print(temperatureInt);
  lcd.setCursor(15, 0);
  lcd.print("C");


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
