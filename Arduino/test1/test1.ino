
// EPCOS 100K Thermistor (B57540G0104F000)
// Thermistor lookup table for RepRap Temperature Sensor Boards (http://make.rrrf.org/ts)
// Made with createTemperatureLookup.py (http://svn.reprap.org/trunk/reprap/firmware/Arduino/utilities/createTemperatureLookup.py)
// ./createTemperatureLookup.py --r0=100000 --t0=25 --r1=0 --r2=4700 --beta=4066 --max-adc=1023
// r0: 100000
// t0: 25
// r1: 0
// r2: 4700
// beta: 4066
// max adc: 1023
#define NUMTEMPS 20
short temptable[NUMTEMPS][2] = {
  {1, 841},
  {54, 255},
  {107, 209},
  {160, 184},
  {213, 166},
  {266, 153},
  {319, 142},
  {372, 132},
  {425, 124},
  {478, 116},
  {531, 108},
  {584, 101},
  {637, 93},
  {690, 86},
  {743, 78},
  {796, 70},
  {849, 61},
  {902, 50},
  {955, 34},
  {1008, 3}
};

void setup() {
  Serial.begin(9600);

}

int t = temptable[0][0];
int i = 0;

int rL = 0, rH = 0;
int tL = 0, tH = 0;
float p = 0;

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(0);


  while (a > t) {
    t = temptable[i][0];
    i = i + 1;
  }

  rL = temptable[i - 1][0];
  rH = temptable[i - 2][0];

  tL = temptable[i - 1][1];
  tH = temptable[i - 2][1];

  //p = map(a, 0, 1023, 0, 5);
  p = (float)(5 * a) / 1024;

  Serial.print("p="); Serial.println(p);

  delay(500);
}
