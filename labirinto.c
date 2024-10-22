//projeto arduino - laritinto de arame

//definicoes dos pinos
#define LED1 1 //pino led9
#define LED2 2 //pino led2
#define LED3 3 //pino led3
#define LED4 4 //pino led4
#define ACT7 7 //pino acionador 
#define BUZZER 8 //pino para buzzer

int erros = 0;

void setup(){
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    //pinMode(SIRENE, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(ACT7, INPUT);
    erros = 0;
}

void loop(){
    digitalWrite(LED1, HIGH);

    if (digitalRead(ACT7) == HIGH){
        erros++;
        if (erros==0){
            noTone(BUZZER);
        } else {
            if (erros <= 4){
                tone(BUZZER, erros*1000);
            }
        }
        digitalWrite(LED2, (erros==1 || erros==4) ? 1 : 0);
        digitalWrite(LED3, (erros==2 || erros==4) ? 1 : 0);
        digitalWrite(LED4, (erros==3 || erros==4) ? 1 : 0);

        digitalWrite(SIRENE, (erros > 4) ? 1 : 0);
    }
   delay(200);
}