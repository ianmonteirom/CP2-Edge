## ![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/06082901-b24b-4d64-a967-aeb734760650)
# 🤖 Edge Computing - CP2 - Sensor de Ambiente
👋 Olá, bem-vindo ao nosso trabalho do Check Point 2 de Edge Computing! Nós somos empresa Data Sphere da turma 1ESPH, e é um imenso prazer apresentar este projeto.



![Data Sphere1000x1000](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/0fe80a9b-6290-417d-8367-2abe3824d0b0)
Logo da nossa equipe
## 🔮 O que é a Data Sphere?
- A Data Sphere Solutions é uma empresa fictícia representando a nossa equipe, formada pelos alunos: <br>
  Artur Alves -    RM 555171 <br>
  Giuliana Lucas - RM 557597 <br>
  Ian Monteiro -   RM 558652 <br>
  Igor Brunelli -  RM 555035 <br>


## 👥 Quem é o nosso cliente?
- Nosso cliente é a Vinheria Agnello, um comércio de vinhos fictício criado pela FIAP para desafiar os alunos a inovar e trabalhar com o mercado desde cedo. O problema da Vinheria Agnello que atenderemos na disciplina de Edge Computing é como podemos preservar a qualidade do vinho sem ele alterar seu sabor de qualquer forma. Conservar vinho é desafiador, pois ele deve estar em luminosidade, umidade e temperatura ideais, para não alterar sua composição química de qualquer maneira possível. Pensando nisso, foi nos passado o trabalho de criar um **Sensor de Ambiente**.


## 🤔 Afinal, no que estamos trabalhando?
- O nosso trabalho para a CP2 de Edge Computing é um sensor de ambiente, um projeto em **Arduino** montado tanto em um simulador on-line quanto na bancada no Hands On.
![image](https://github.com/ianmonteirom/CP2-Edge/assets/152393807/8ee457a6-1f2d-448f-b176-9c2a8d6bc455)
- Na imagem acima, temos o projeto pronto no simulador on-line **(Link do projeto: https://wokwi.com/projects/395277160338652161)**


## 📝 Lista de Materiais
- x1 Placa Arduino Uno;
- x1 Breadboard;
- x1 Sensor DHT11 ou DH22, depende de onde o projeto será montado. O DHT11 será utilizado na bancada e o DHT22 será utilizado no simulador, por ser o único disponibilizado pelo software;
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

