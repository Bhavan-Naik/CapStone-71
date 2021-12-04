#define potentiometer A0
#define sensorPin A1

#define R_led 2 
#define Relay 6 

int read_ADC =0;
int set_timer =0;
int sensor =0;
int seconds =0 ,timer=0;
int flag=0;
long delay_Start;


void setup(){

Serial.begin(9600);
  
pinMode(sensorPin, INPUT);

pinMode(R_led,OUTPUT);
pinMode(Relay,OUTPUT);
digitalWrite(Relay, HIGH);

delay(1000);
}

void loop(){
read_ADC = analogRead(potentiometer);
set_timer = read_ADC /17.05;

sensor = digitalRead(sensorPin);

if(sensor==1){
Serial.println("Motion detected!");
digitalWrite(R_led, HIGH); // LED Turn On 
digitalWrite(Relay, LOW); // Relay Turn On 
seconds = 0;
flag=1;
delay_Start = millis();
}
else{
Serial.println("Motion stopped!");
digitalWrite(R_led, LOW); // LED Turn Off.  
}

if((flag==1) && (millis()- delay_Start) > 999){ 
seconds = seconds+1;  
delay_Start = millis();
}

if(seconds>set_timer){
flag=0;
seconds=0; 
digitalWrite(Relay, HIGH); // Relay Turn Off   
}

delay(100);
}
