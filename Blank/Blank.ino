void setup() {
  // put your setup code here, to run once:

}
int a;
int *p;
void loop() {
  // put your main code here, to run repeatedly:
p = &a;
Serial.println(int(p));
Serial.println(*p);
}
