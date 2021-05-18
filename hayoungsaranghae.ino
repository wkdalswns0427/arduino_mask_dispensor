// 아두이노 우노, LED, 초음파 센서, L2978n 모터드라이버, DC모터(6V)
int trig = 2;
int echo = 3;
int spd = 6;
int In1 = 5
int In2 = 4;
//int buzzer = 8;
int LED = 13;
float duration;
float distance;

void setup() 
{
  Serial.begin(9600);
  //초음파
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  //모터 (DC모터)
  pinMode(spd, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  #pinMode(buzzer,OUTPUT);
  #pinMode(LED, OUTPUT);
}

void loop() 
{
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = ((34000*duration)/1000000)/2;
  Serial.print(distance);
  Serial.println("cm");

  if(distance < 100)
  {
    analogWrite(LED,255-(distance*12));

    digitalWrite(In1, HIGH); #방향
    digitalWrite(In2, LOW); #방향
    digitalWrite(spd, 255); #속도 설정
    delay(1000); # 1000미리세컨드 동안 회전
    digitalWrite(speed, 0);
    #tone(buzzer,1000,100);
    #delay(100);
    #tone(buzzer,1000,100);
    delay(10000);
  }
  else
  {
    digitalWrite(LED,LOW);
    digitalWrite(speed, 0);
  }
  
  delay(100);
}
