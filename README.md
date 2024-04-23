## ![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/06082901-b24b-4d64-a967-aeb734760650)
# 🤖 Edge Computing - CP2 - Sensor de Ambiente
👋 Olá, bem-vindo ao nosso trabalho do Check Point 2 de Edge Computing! Nós somos a empresa Data Sphere da turma 1ESPH, e é um imenso prazer apresentar este projeto.



![Data Sphere1000x1000](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/0fe80a9b-6290-417d-8367-2abe3824d0b0)
Logo da nossa equipe
## 🔮 O que é a Data Sphere?
A Data Sphere Solutions é uma empresa fictícia representando a nossa equipe, formada pelos alunos: 
- Artur Alves -    RM 555171 
- Giuliana Lucas - RM 557597
- Ian Monteiro -   RM 558652 
- Igor Brunelli -  RM 555035 


## 👥 Quem é o nosso cliente?
- Nosso cliente é a Vinheria Agnello, um comércio de vinhos fictício criado pela FIAP para desafiar os alunos a inovar e trabalhar com o mercado desde cedo. O problema da Vinheria Agnello que atenderemos na disciplina de Edge Computing é como podemos preservar a qualidade do vinho sem ele alterar seu sabor de qualquer forma. Conservar vinho é desafiador, pois ele deve estar em luminosidade, umidade e temperatura ideais, para não alterar sua composição química de qualquer maneira possível. Pensando nisso, foi nos passado o trabalho de criar um **Sensor de Ambiente**.


## 🤔 Afinal, no que estamos trabalhando?
- O nosso trabalho para a CP2 de Edge Computing é um sensor de ambiente, um projeto em **Arduino** montado tanto em um simulador on-line quanto na bancada no Hands On.
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/8ee457a6-1f2d-448f-b176-9c2a8d6bc455)
- Na imagem acima, temos o projeto pronto no simulador on-line **(Link do projeto: https://wokwi.com/projects/395277160338652161)**


## 📝 Lista de Materiais
- x1 Placa Arduino Uno;
- x1 Breadboard;
- x1 Sensor DHT11 ou DHT22, depende de onde o projeto será montado. O DHT11 será utilizado na bancada e o DHT22 será utilizado no simulador, por ser o único disponibilizado pelo software;
- x1 Display LCD 16 x 2;
- x1 Fotoresistor LDR;
- x1 Buzzer (Buzina);
- x1 LED Verde;
- x1 LED Amarelo;
- x1 LED Vermelho;
- x4 Resistores de 220Ω;
- Aproximadamente x24 Cabos jumper;


## ❓ E como o projeto funciona?
- O projeto é um **Sensor de Ambiente**, ou seja, ele basicamente capta a Luminosidade, a Umidade e a Temperatura do ambiente, e informa ao usuário uma média de 10 leituras de valores tanto no display quanto no serial. A cada 5 segundos, as informações do display mudam, alternando entre o valor da Luminosidade, Umidade e Temperatura, e seu estado (Ok, em Alerta, Estado crítico)
- Enquanto o ambiente está escuro, o LED Verde ficará aceso, indicando que a Luminosidade está OK;
- Caso o ambiente fique a meia luz, o LED Amarelo acenderá no lugar, indicando estado de alerta para a Luminosidade;
- Caso o ambiente fique totalmente iluminado, o LED Vermelho acenderá no lugar e a buzina apitará, indicando estado crítico para a Luminosidade;
- Enquanto o ambiente estiver na temperatura e umidade ideal, o LED Verde ficará aceso;
- Caso a temperatura saia da faixa ideal, o LED Amarelo acenderá no lugar, e a buzina apitará;
- Caso a umidade saia da faixa ideal, o LED Vermelho acenderá no lugar, e a buzina apitará;
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/cba33926-f182-4dfc-8e67-8f154cd813c1)
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/3cd40ac3-9e87-4dce-96bb-549175007137)
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/c7baf9ef-dcc2-4de2-9b17-13e1762361d5)
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/34b436bd-9624-418d-af31-f2e337ed9595)
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/a022d7bf-f0d5-4d19-be5b-264eff3a0a3a)
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/2622bb69-5d0b-49d2-9b98-dd858bfd1126)
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/35ee3e90-3f01-4acf-83d6-2c39c1621fff)
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/5e1c7271-36ad-4a2e-8c62-983173f94218)
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/7fb84fb1-7ae1-4cf8-9c80-d9ad53d75151)
- Com todas essas funcionalidades, a Vinheria Agnello ficará satisfeita com nosso trabalho, utilizando o sensor de ambiente para monitorar seus vinhos.


## 🖥️ O Código do Projeto
- O Código para o Arduino é desenvolvido em C++, em um arquivo .ino:
```
// Adicionando as bibliotecas para o Display e o DHT
#include <LiquidCrystal.h>
#include <DHT.h>

// Definindo o pino do DHT, o tipo do DHT, o número de leituras para o cálculo da média e os pinos dos LEDs
#define DHTPIN 7     // Pino de dados do DHT22 conectado ao pino digital 7
#define DHTTYPE DHT22   // Tipo do sensor DHT
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
  lcd.clear();                  
  lcd.createChar(0, logo0x3);
  lcd.createChar(1, logo0x4);
  lcd.createChar(2, logo0x5);
  lcd.createChar(3, logo1x3);
  lcd.createChar(4, logo1x4);
  lcd.createChar(5, logo1x5);


  // Mostrando o LOGO no Display
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

    Serial.print("Ambiente ESCURO: ");

    // Escreve no display no estado da umidade
    lcd.setCursor(0, 1);
    lcd.print("OK");


} else if (luminosity > 15 && luminosity <= 50) {
    // Faça algo se a luminosidade estiver moderada
    // Desliga os outros LEDs e liga o amarelo, indicando luminosidade moderada (alerta)
    digitalWrite(LEDG, LOW); // Desliga o LED verde
    digitalWrite(LEDY, HIGH);  // Liga o LED amarelo
    digitalWrite(LEDR, LOW);  // Desliga o LED vermelho

    Serial.print("Ambiente a MEIA LUZ: ");

    // Escreve no display no estado da umidade
    lcd.setCursor(0, 1);
    lcd.print("MEIA LUZ");

} else {
    // Faça algo se a luminosidade estiver alta
    // Desliga os outros LEDs e liga o vermelho, indicando luminosidade alta (estado crítico)
    digitalWrite(LEDG, LOW); // Desliga o LED verde
    digitalWrite(LEDY, LOW);  // Desliga o LED amarelo
    digitalWrite(LEDR, HIGH);  // Liga o LED vermelho

    tone(BUZZER, 2000, 5000); // Dispara a buzina a uma frequência DE 2000Hz por 5 segundos

    Serial.print("Ambiente ILUMINADO: ");

    // Escreve no display no estado da umidade
    lcd.setCursor(0, 1);
    lcd.print("ALTA");

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

}
```


## 🔍 Problemas e Desafios Encontrados
Durante o desenvolvimento do projeto enfrentamos diversos problemas e desafios a serem solucionados, como:
- O projeto utiliza mais componentes do que os projetos anteriores realizados ao longo da disciplina;
- As entradas do Arduino estão praticamente sendo todas utilizadas, dificultando a inserção de todas as funcionalidades;
- Montagem e estruturação de todo o código do projeto, na qual tivemos que pensar em várias funcionalidades diferentes e inéditas para nós;
- O Wokwi (Simulador on-line utilizado) possui somente o DHT22, enquanto na bancada utilizaremos o DHT11, sendo necessário a alteração de uma linha do código dependendo de onde utilizaremos o projeto;
- O Fotorresistor do Wokwi é diferente do antigo simulador que estávamos utilizando (Tinkercad);
- 
