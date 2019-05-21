int PWM_PIN1 = 3;             
int PWM_PIN2 = 2;                     // Connecting receiver signal Pins with Arduino Board

int M1 = 6;                             //Motor 1
int M2 = 11;                            //Motor 2

int DM1_F = 8;                          //Forward
int DM1_B = 7;                          //Backward                      Motor 1 Direction Pins

int DM2_F = 10;                         //Forward
int DM2_B = 9;                          //Backward                      Motor 2 Direction Pins

int low1 = 1350, middle1 = 1550, high1 = 1740;           //min and max value that can be received from receiver
int low2 = 1140, middle2 = 1440,  high2 = 1730;

int speed1, speed2;                     //Speeds 
int PWM_v1, PWM_v2;                     //PWM Value received from Receiver Pins
int v1, v2;                             //Variables
 
void setup() {
  
  pinMode(PWM_PIN1, INPUT);
  pinMode(PWM_PIN2, INPUT);
  pinMode(DM1_F, OUTPUT);
  pinMode(DM1_B, OUTPUT);
  pinMode(DM2_F, OUTPUT);
  pinMode(DM2_B, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  
  Serial.begin(9600);
}
 
void loop() {
  
 PWM_v1 = pulseIn(PWM_PIN1,HIGH);
 PWM_v2 = pulseIn(PWM_PIN2,HIGH);
 
 v1 = constrain(PWM_v1, low1, high1);            
 v2 = constrain(PWM_v2, low2, high2);  
 
 
 if(v1>middle1)
  {
    digitalWrite(DM1_F, HIGH);
    digitalWrite(DM1_B, LOW);
    speed1 = map(v1,middle1,high1,0,255);
  }
 else
  {
    digitalWrite(DM1_F, LOW);
    digitalWrite(DM1_B, HIGH);
    speed1 = map(v1,low1,middle1,255,0);
  }

analogWrite(M1,speed1);
 
 if(v2>middle2)
  {
      digitalWrite(DM2_F, HIGH);
      digitalWrite(DM2_B, LOW);
      speed2 = map(v2,middle2,high2,0,255);
  }
 else
  {
      digitalWrite(DM2_F, LOW);
      digitalWrite(DM2_B, HIGH);
      speed2 = map(v2,low2,middle2,255,0);
  }
  
analogWrite(M2,speed2);
  
 if(PWM_v1==0 && PWM_v2==0)
  {
  analogWrite(M1,0);
  analogWrite(M2,0);
  }
  
}
