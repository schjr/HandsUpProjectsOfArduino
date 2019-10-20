class Module
{
  public:
  virtual void initial();
};
class laser
{
  public:
  laser(int pin);
  void openIt();
  void closeIt();
  private:
  int m_pin;
};
laser::laser(int pin)
{
  m_pin = pin;
  digitalWrite(m_pin,LOW);
}
void laser::openIt()
{
  digitalWrite(m_pin,HIGH);
}
void laser::closeIt()
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
class DigitalLight:public Module
{
  public:
  DigitalLight(int a,int b,int c,int d,int e,int f,int g,int dp);
  ~DigitalLight();
  void initial();
  void showNum(int num);
  private:
  int* m_pin=nullptr;
  int* m_status=nullptr;
  void showControl(bool a,bool b,bool c,bool d,bool e,bool f,bool g,bool dp);
};
DigitalLight::~DigitalLight()
{
  delete []m_pin;
  delete []m_status;
}
DigitalLight::DigitalLight(int a,int b,int c,int d,int e,int f,int g,int dp)
{
  m_pin = new int[8];
  m_status = new int[8];
  m_pin[0]=a;
  m_pin[1]=b;
  m_pin[2]=c;
  m_pin[3]=d;
  m_pin[4]=e;
  m_pin[5]=f;
  m_pin[6]=g;
  m_pin[7]=dp;
}
void DigitalLight::initial()
{
  for(int i = 0;i<8;i++)
  {
    pinMode(m_pin[i],OUTPUT);
  }
  showNum(-2);
}
void DigitalLight::showControl(bool a,bool b,bool c,bool d,bool e,bool f,bool g,bool dp)
{
  m_status[0]=a;
  m_status[1]=b;
  m_status[2]=c;
  m_status[3]=d;
  m_status[4]=e;
  m_status[5]=f;
  m_status[6]=g;
  m_status[7]=dp;
}
void DigitalLight::showNum(int num)
{
  switch (num)
  {
    case -1:
    showControl(LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW);
    break;
    case 0:
    showControl(LOW,LOW,LOW,LOW,LOW,LOW,HIGH,HIGH);
    break;
    case 1:
    showControl(HIGH,LOW,LOW,HIGH,HIGH,HIGH,HIGH,HIGH);
    break;
    case 2:
    showControl(LOW,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH);
    break;
    case 3:
    showControl(LOW,LOW,LOW,LOW,HIGH,HIGH,LOW,HIGH);
    break;
    case 4:
    showControl(HIGH,LOW,LOW,HIGH,HIGH,LOW,LOW,HIGH);
    break;
    case 5:
    showControl(LOW,HIGH,LOW,LOW,HIGH,LOW,LOW,HIGH);
    break;
    case 6:
    showControl(LOW,HIGH,LOW,LOW,LOW,LOW,LOW,HIGH);
    break;
    case 7:
    showControl(LOW,LOW,LOW,HIGH,HIGH,HIGH,HIGH,HIGH);
    break;
    case 8:
    showControl(LOW,LOW,LOW,LOW,LOW,LOW,LOW,HIGH);
    break;
    case 9:
    showControl(LOW,LOW,LOW,LOW,HIGH,LOW,LOW,HIGH);
    break;
    default:
    showControl(HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH);
    break;
  }
  for(int i=0;i<8;i++)
  {
    digitalWrite(m_pin[i],m_status[i]);
  }
}
DigitalLight l1(2,3,4,5,6,7,8,9);
Ultrasound u1(11,12);
laser la1(10);
void setup() {
  // put your setup code here, to run once:
  u1.initial();
  l1.initial();
}

void loop() {
  la1.openIt();
  Serial.println(u1.getDist());
  int numshow = u1.getDist()/10;
  l1.showNum(numshow);
  // put your main code here, to run repeatedly:

}
