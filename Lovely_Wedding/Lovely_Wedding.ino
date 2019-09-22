int a=7;
int b=6;
int c=5;// 定义数字接口5 连接c 段数码管
int d=10;// 定义数字接口10 连接d 段数码管
int e=11;// 定义数字接口11 连接e 段数码管
int f=8;// 定义数字接口8 连接f 段数码管
int g=9;// 定义数字接口9 连接g 段数码管
int dp=4;// 定义数字接口4 连接dp 段数码管
void digital_0(void) //显示数字5
{
unsigned char j;
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,LOW);
digitalWrite(f,LOW);
digitalWrite(g,HIGH);
digitalWrite(dp,HIGH);
}
void digital_1(void) //显示数字1
{
unsigned char j;
digitalWrite(c,LOW);//给数字接口5 引脚高电平，点亮c 段
digitalWrite(b,LOW);//点亮b 段
for(j=7;j<=11;j++)//熄灭其余段
digitalWrite(j,HIGH);
digitalWrite(dp,HIGH);//熄灭小数点DP 段
}
void digital_2(void) //显示数字2
{
unsigned char j;
digitalWrite(b,LOW);
digitalWrite(a,LOW);
for(j=9;j<=11;j++)
digitalWrite(j,LOW);
digitalWrite(dp,HIGH);
digitalWrite(c,HIGH);
digitalWrite(f,HIGH);
}
void digital_3(void) //显示数字3
{
digitalWrite(g,LOW);
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(dp,HIGH);
digitalWrite(f,HIGH);
digitalWrite(e,HIGH);
}
void digital_4(void) //显示数字4
{
digitalWrite(c,LOW);
digitalWrite(b,LOW);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
digitalWrite(dp,HIGH);
digitalWrite(a,HIGH);
digitalWrite(e,HIGH);
digitalWrite(d,HIGH);
}
void digital_5(void) //显示数字5
{
unsigned char j;
digitalWrite(a,LOW);
digitalWrite(b,HIGH);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e, HIGH);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
digitalWrite(dp,HIGH);
}
void digital_6(void) //显示数字6
{
unsigned char j;
for(j=7;j<=11;j++)
digitalWrite(j,LOW);
digitalWrite(c,LOW);
digitalWrite(dp,HIGH);
digitalWrite(b,HIGH);
}
void digital_7(void) //显示数字7
{
unsigned char j;
for(j=5;j<=7;j++)
digitalWrite(j,LOW);
digitalWrite(dp,HIGH);
for(j=8;j<=11;j++)
digitalWrite(j,HIGH);
}
void digital_8(void) //显示数字8
{
unsigned char j;
for(j=5;j<=11;j++)
digitalWrite(j,LOW);
digitalWrite(dp,HIGH);
}
void digital_9(void) //显示数字5
{
unsigned char j;
digitalWrite(a,LOW);
digitalWrite(b,LOW);
digitalWrite(c,LOW);
digitalWrite(d,LOW);
digitalWrite(e,HIGH);
digitalWrite(f,LOW);
digitalWrite(g,LOW);
digitalWrite(dp,HIGH);
}
void digital(void)
{
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
digitalWrite(dp,HIGH);
}
void setup()
{
int i;//定义变量
for(i=4;i<=11;i++)
pinMode(i,OUTPUT);//设置4～11 引脚为输出模式
pinMode(12,OUTPUT);
pinMode(13,INPUT);
Serial.begin(9600);
}
#define oop distance
unsigned long distance;
int get1 = -1;
int temp = -1;
void loop() {
//digital();
//get1=(Serial.read()-48);
digitalWrite(12, LOW);
delayMicroseconds(2);
digitalWrite(12, HIGH);
delayMicroseconds(10);
digitalWrite(12, LOW);
distance = pulseIn(13, HIGH) / 58.00;
oop %= 10;
if(oop>=0&&oop<=10)
{
  temp = oop;
}
//part1:;
switch(temp)
{
    case(0):
  digital_0();
  break;
    case(1):
  digital_1();
  break;
    case(2):
  digital_2();
  break;
    case(3):
  digital_3();
  break;
    case(4):
  digital_4();
  break;
    case(5):
  digital_5();
  break;
    case(6):
  digital_6();
  break;
    case(7):
  digital_7();
  break;
    case(8):
  digital_8();
  break;
    case(9):
  digital_9();
  break;
    case(10):
  digital();
  break;
  default:
  digital();
  break;
}
/*
if(oop>=0&&oop<10)
{
  digital_0();
  delay(1000);
}
else if(oop>=10&&oop<20)
{
  digital_1();
  delay(1000);
}
else if(oop>=20&&oop<30)
{
  digital_2();
  delay(1000);
}
else if(oop>=30&&oop<40)
{
  digital_3();
  delay(1000);
}
else if(oop>=40&&oop<50)
{
  digital_4();
  delay(1000);
}
else if(oop>=50&&oop<60)
{
  digital_5();
  delay(1000);
}
else if(oop>=60&&oop<70)
{
  digital_6();
  delay(1000);
}
else if(oop>=70&&oop<80)
{
  digital_7();
  delay(1000);
}
else if(oop>=80&&oop<90)
{
  digital_8();
  delay(1000);
}
else if(oop>=90&&oop<100)
{
  digital_9();
  delay(1000);
}
else
{
  digital();
}
*/
Serial.println(oop);
//delay(1000);
  // put your main code here, to run repeatedly:

}
