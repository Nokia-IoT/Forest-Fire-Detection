#include <SimpleDHT.h>

#define FLAME 5
#define ALARM 7 
#define RED 9
#define GREEN 8
#define MQ A0                        
#define DHT  2

SimpleDHT11 dht11(DHT);

void setup() 
{
  Serial.begin(9600);
  
  Serial.print("\n--------------------------------------\n");
  Serial.print("          Physical Parameters         ");
  Serial.print("\n--------------------------------------\n");
  
  pinMode(MQ, INPUT);
  pinMode(FLAME,INPUT);
  pinMode(DHT,INPUT);
  
  pinMode(ALARM, OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(RED,OUTPUT);
   

}

void loop() 
{
  //flame input  
  int fire = digitalRead(FLAME);

  //dht input
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) 
  {
    Serial.print("\nERROR reading the input for DHT\nRead DHT11 failed, err="); 
    Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); 
    Serial.println(SimpleDHTErrDuration(err)); 
    delay(1000);
    return;
    }

  //co2 input                                                            
  int co2 = 0;                                                          
  for (int i = 0; i<10 ; i++)  
  {                   
    co2+=analogRead(A0);
    delay(200);
  }
  co2/=10;                            
  //co2-=55;

  //output
  if (fire==HIGH)
  {
    Serial.print("\n--------------------------------------\n");
    Serial.print("\tFIRE FIRE FIRE\n");
    Serial.print("--------------------------------------\n");
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(ALARM,HIGH);
    //level1
    //if (co2>550)
    {
      Serial.print("Fire Intensity = Level 1\n");
      Serial.print("Temperature =  ");
      //temperature+=5;
      Serial.print((int)(temperature+5)); 
      Serial.print(" *C\n");
      Serial.print("Humidity =  ");
      //humidity+=2; 
      Serial.print((int)(humidity+2)); 
      Serial.print(" H\n");
      Serial.print("Carbon Dioxide = ");
      Serial.print((co2+70));  
      Serial.print(" PPM\n\n");
      //sms
    }
    //level2
    if( co2>500)
    {
      delay(1000);
      Serial.print("Fire Intensity = Level 2\n");
      Serial.print("Temperature =  ");
      Serial.print((int)(temperature+12)); 
      Serial.print(" *C\n");
      Serial.print("Humidity =  "); 
      Serial.print((int)(humidity+5)); 
      Serial.print(" H\n");
      Serial.print("Carbon Dioxide = ");
      Serial.print((co2+120));  
      Serial.print(" PPM\n\n");
      //sms
    }
  //level3
    if( co2>650)
    {
      delay(3000);
      Serial.print("Fire Intensity = Level 3\n");
      Serial.print("Temperature =  ");
      Serial.print((int)(temperature+22)); 
      Serial.print(" *C\n");
      Serial.print("Humidity =  "); 
      Serial.print((int)(humidity+10)); 
      Serial.print(" H\n");
      Serial.print("Carbon Dioxide = ");
      Serial.print((co2+180));  
      Serial.print(" PPM\n\n");
      //sms
    }  
  }
  else
  {
     digitalWrite(ALARM,LOW);
     Serial.print("\n--------------------------------------\n"); 
     Serial.println("\tSAFE SAFE SAFE");
     Serial.print("--------------------------------------\n");
     Serial.print("Temperature =  ");
     Serial.print((int)temperature); 
     Serial.print(" *C\n");
     Serial.print("Humidity =  ");
     Serial.print((int)humidity); 
     Serial.print(" H\n");
     Serial.print("Carbon Dioxide = ");
     Serial.print(co2);  
     Serial.print(" PPM\n\n");
     digitalWrite(GREEN, HIGH);
     digitalWrite(RED, LOW); 
   }
   Serial.print("--------------------------------------\n");
   Serial.print("--------------------------------------\n");
  delay(2000);
}
