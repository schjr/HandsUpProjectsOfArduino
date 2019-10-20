class Module
{
  public:
  virtual void initial();
};
class NewChip:public Module
{
  public:
  NewChip(int latchP,int clockP,int dataP);
  void initial();
  void m_display(int num);
  private:
  int m_latchP;
  int m_clockP;
  int m_dataP;
};
void NewChip::m_display(int num)
{
  digitalWrite(m_latchP,LOW);
  switch (num)
  {
    case 10:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 0);
    break;
    case 0:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 129);
    break;
    case 1:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 243);
    break;
    case 2:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 73);
    break;
    case 3:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 97);
    break;
    case 4:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 51);
    break;
    case 5:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 37);
    break;
    case 6:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 5);
    break;
    case 7:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 241);
    break;
    case 8:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 1);
    break;
    case 9:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 33);
    break;
    default:
    shiftOut(m_dataP, m_clockP, MSBFIRST, 255);
    break;
  }
  digitalWrite(m_latchP,HIGH);
}
NewChip::NewChip(int latchP,int clockP,int dataP)
{
  m_latchP = latchP;
  m_clockP = clockP;
  m_dataP = dataP;
}
void NewChip::initial()
{
  pinMode(m_latchP,OUTPUT);
  pinMode(m_clockP,OUTPUT);
  pinMode(m_dataP,OUTPUT);
}
class Laser
{
  public:
  Laser(int pin);
  void openIt();
  void closeIt();
  private:
  int m_pin;
};
Laser::Laser(int pin)
{
  m_pin = pin;
  digitalWrite(m_pin,LOW);
}
void Laser::openIt()
{
  digitalWrite(m_pin,HIGH);
}
void Laser::closeIt()
{
  digitalWrite(m_pin,LOW);
}
class Ultrasound:public Module
{
  public:
  Ultrasound(int trig,int echo);
  int getDist();
  void initial();
  private:
  int m_trig;
  int m_echo;
};
Ultrasound::Ultrasound(int trig,int echo)
{
  m_trig = trig;
  m_echo = echo;
}
void Ultrasound::initial()
{
  Serial.begin(9600);
  pinMode(m_trig,OUTPUT);
  pinMode(m_echo,INPUT);
}
int Ultrasound::getDist()
{
  digitalWrite(m_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(m_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(m_trig, LOW);
  return pulseIn(m_echo, HIGH) / 58.00;
  delay(500);
}
NewChip c1(6,5,4);
Ultrasound u1(11,12);
Laser la1(10);
void setup() {
  // put your setup code here, to run once:
  u1.initial();
  c1.initial();
}

void loop() {
  la1.openIt();
  Serial.println(u1.getDist());
  c1.m_display(u1.getDist()/10);
  // put your main code here, to run repeatedly:

}
