

int kirmiziPin = 9;
int yesilPin = 10;
int maviPin = 11;
int lm35Pin = A0;
 

void setup(){
  
Serial.begin(9600);
analogReference(INTERNAL);
pinMode(kirmiziPin, OUTPUT);
pinMode(yesilPin, OUTPUT);
pinMode(maviPin, OUTPUT);

}
 
void loop(){
  
  int sicaklikVolt = analogRead(lm35Pin);
  float sicaklikC = sicaklikC = sicaklikVolt / 9.31; 
  Serial.println(sicaklikC);

  if(sicaklikC > 26){
    renkAyarla(0, 255, 255);  // Mavi 
    Serial.println("mavi");
   
  }

  if(sicaklikC > 27){
    renkAyarla(255, 255, 0);  // sari
    Serial.println("sari");
    
    
  }
  
  if(sicaklikC > 28){
    renkAyarla(255, 0, 0);  // kırmızı
    Serial.println("kirmizi");
  }
}
 
void renkAyarla(int kirmizi, int yesil, int mavi)
{
 
kirmizi = 255 - kirmizi;
 
yesil = 255 - yesil;
 
mavi = 255 - mavi;
 
analogWrite(kirmiziPin, kirmizi);
 
analogWrite(yesilPin, yesil);
 
analogWrite(maviPin, mavi);
 
}
