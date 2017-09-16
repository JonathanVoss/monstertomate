//Update 31.Aug.2017

int lev;
int zaehler = 0;

void fuellen(){
  digitalWrite(2, HIGH);
  while(messen()<300 && zaehler<5){
  delay(1000);
  zaehler++;}
  digitalWrite(2, LOW);

  if(zaehler>4){
    digitalWrite(4, HIGH); //Serial to ESP
  }
  
  if(zaehler<5){
    zaehler = 0;
  }
  
}

void nebeln(){
  digitalWrite(3, HIGH); //fogger
  delay(5000);
  digitalWrite(5, HIGH); //fan
  delay(7000);
  digitalWrite(3, LOW);
  delay(1000);
  digitalWrite(5, LOW);
  
}

int messen(){
  digitalWrite(7, HIGH);
  lev = analogRead(A0);
  digitalWrite(7, LOW);
  return lev;
}

void setup() {
  pinMode(2, OUTPUT); //pump
  pinMode(3, OUTPUT); //fogger
  pinMode(5, OUTPUT); //fan
  pinMode(7, OUTPUT); //Messleitung
  pinMode(4, OUTPUT); //Serial to ESP
  digitalWrite(4, LOW); //Serial to ESP

}

void loop() {
  
  if(messen()<300 && zaehler<5){
    fuellen();}
  
  if(zaehler<5){
    nebeln();
  }
  for(int i = 0; i<45; i++)
  delay(1000);

}
