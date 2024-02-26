const int switch1pin1=2;//set up digital pin 2 for controlling switch 1
const int switch1pin2=3;//set up digital pin 3 for controlling switch 1
const int button=A0;//set up analog pin A0 for reading button 1
const int R1 = 4;
const int Y1 = 5;
const int G1 = 6;
const int R2 = 7;
const int Y2 = 8;
const int G2 = 9;
const int R3 = 10;
const int Y3 = 11;
const int G3 = 12;
const int R4 = 13;
const int Y4 = 14;
const int G4 = 15;
const int R5 = 16;
const int Y5 = 17;
const int G5 = 18;
const int R6 = 19;
const int Y6 = 20;
const int G6 = 21;
const int R7 = 22;
const int Y7 = 23;
const int G7 = 24;
const int R8 = 25;
const int Y8 = 26;
const int G8 = 27;
int State1=0;//Sets our value for the state of switch 1

void setup() {
  Serial.begin(9600);//sets up our readings in the serial monitor and the baud rate of 9600
  pinMode(switch1pin1,OUTPUT);
  pinMode(switch1pin2,OUTPUT);
  pinMode(G1,OUTPUT);
  pinMode(Y1,OUTPUT);
  pinMode(R1,OUTPUT);
  pinMode(G2,OUTPUT);
  pinMode(Y2,OUTPUT);
  pinMode(R2,OUTPUT);
  pinMode(G3,OUTPUT);
  pinMode(Y3,OUTPUT);
  pinMode(R3,OUTPUT);
  pinMode(G4,OUTPUT);
  pinMode(Y4,OUTPUT);
  pinMode(R4,OUTPUT);
  pinMode(G5,OUTPUT);
  pinMode(Y5,OUTPUT);
  pinMode(R5,OUTPUT);
  pinMode(G6,OUTPUT);
  pinMode(Y6,OUTPUT);
  pinMode(R6,OUTPUT);
  pinMode(G7,OUTPUT);
  pinMode(Y7,OUTPUT);
  pinMode(R7,OUTPUT);
  pinMode(G8,OUTPUT);
  pinMode(Y8,OUTPUT);
  pinMode(R8,OUTPUT);
  pinMode(button,INPUT);
}
enum SWITCHSTATES
{
  ST_OFF,
  ST_STRAIGHT,
  ST_TURN,
};//Sets up states that arduino can hop between

SWITCHSTATES switchState=ST_OFF;

void loop(){
  //Serial.println("State 1");
  //Serial.println(State1);//display in serial monitor what the State of State 1 is with the text "State 1" in front.
  

int ButtonRead=analogRead(button);//Stores value for button1

  Serial.println("Button");
  Serial.println(ButtonRead);//display in serial monitor what the State of Button 1 is with the text "Button 1" in front.
  delay(200);// 0.2 second pause between readings
  switch(switchState)
  {
    case ST_OFF:
    switchoff(ButtonRead,State1);
    break;
    case ST_STRAIGHT:
    switchstraight(ButtonRead);
    break;
    case ST_TURN:
    switchturn(ButtonRead);
    break;
    
  }
}

void switchoff(int ButtonRead, int State1){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,LOW);
if ((ButtonRead<500) && (State1==0)){
    digitalWrite(R1, HIGH);
    digitalWrite(Y1, HIGH);
    digitalWrite(G1, LOW);
    digitalWrite(R2, LOW);
    digitalWrite(Y2, HIGH);
    digitalWrite(G2, HIGH);
    digitalWrite(R3, HIGH);
    digitalWrite(Y3, HIGH);
    digitalWrite(G3, LOW);
    digitalWrite(R4, LOW);
    digitalWrite(Y4, HIGH);
    digitalWrite(G4, HIGH);
    digitalWrite(R5, HIGH);
    digitalWrite(Y5, HIGH);
    digitalWrite(G5, LOW);
    digitalWrite(R6, LOW);
    digitalWrite(Y6, HIGH);
    digitalWrite(G6, HIGH);
    digitalWrite(R7, HIGH);
    digitalWrite(Y7, HIGH);
    digitalWrite(G7, LOW);
    digitalWrite(R8, LOW);
    digitalWrite(Y8, HIGH);
    digitalWrite(G8, HIGH);
}
  
 if ((ButtonRead<500) && (State1==1)){
    digitalWrite(R1, LOW);
    digitalWrite(Y1, HIGH);
    digitalWrite(G1, HIGH);
    digitalWrite(R2, HIGH);
    digitalWrite(Y2, HIGH);
    digitalWrite(G2, LOW);
    digitalWrite(R3, LOW);
    digitalWrite(Y3, HIGH);
    digitalWrite(G3, HIGH);
    digitalWrite(R4, HIGH);
    digitalWrite(Y4, HIGH);
    digitalWrite(G4, LOW);
    digitalWrite(R5, LOW);
    digitalWrite(Y5, HIGH);
    digitalWrite(G5, HIGH);
    digitalWrite(R6, HIGH);
    digitalWrite(Y6, HIGH);
    digitalWrite(G6, LOW);
    digitalWrite(R7, LOW);
    digitalWrite(Y7, HIGH);
    digitalWrite(G7, HIGH);
    digitalWrite(R8, HIGH);
    digitalWrite(Y8, HIGH);
    digitalWrite(G8, LOW);
 }
  if ((ButtonRead>500) && (State1==1)){
    switchState=ST_STRAIGHT;//sends to straight 1 with button press
  }
  if ((ButtonRead>500) && (State1==0)){
    switchState=ST_TURN;//sends to turn 1 with button press
  }

}

void switchstraight(int ButtonRead){
  digitalWrite(switch1pin1,HIGH);//powers on turnout
  digitalWrite(switch1pin2,LOW);
  delay(500);//keep power to the turnout for 0.5 seconds
  State1=0;//sets value to 0
  switchState=ST_OFF;
}

void switchturn(int ButtonRead){
  digitalWrite(switch1pin1,LOW);
  digitalWrite(switch1pin2,HIGH);//powers on turnout
  delay(500);//keep power to the turnout for 0.5 seconds
State1=1;//sets value to 1
  switchState=ST_OFF;
}  
