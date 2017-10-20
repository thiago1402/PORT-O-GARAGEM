const int LM35 = A0;
    float temperatura = 0;
    int ADClido = 0;
    const int Buzzer = 11;
    
    void setup(){
      analogReference(INTERNAL); //No Mega, use INTERNAL1V1, no Leonardo remova essa linha
      pinMode(Buzzer, OUTPUT);
        Serial.begin(9600);

    }
    
    void loop(){
      ADClido = analogRead(LM35);
      temperatura = ADClido * 0.1075268817204301; //no Leonardo use 0.4887585532
      if(temperatura > 25){ // setei como 25ºC
        delay(1000);
            ADClido = analogRead(LM35);
        temperatura = ADClido * 0.1075268817204301; //no Leonardo use 0.4887585532
        if(temperatura > 25){
          tone(Buzzer, 1000);
        }
      }
      else{
        noTone(Buzzer);
      }
            Serial.println(temperatura );

    }
