void setup()
{
  Wire.begin();
  Serial.begin(9600); //check all; 9600 for PC display, 115200 for communication
  Serial2.begin(115200);
  Serial3.begin(115200);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(8, OUTPUT);
  serdumpR.attach(SerDR);
  serdumpL.attach(SerDL);
  sersweep.attach(Serswp);

  serdumpL.write(0);
  serdumpR.write(180);
  sersweep.write(170);
  /*while (millis() < 6000) { //Callibration at the start
    light[0] = analogRead(LDR_0);
    light[1] = analogRead(LDR_1);
    light[2] = analogRead(LDR_2);
    light[3] = analogRead(LDR_3);
    light[4] = analogRead(LDR_4); //A4 is spoilt
    for(int i=0; i<5; i++){
      if(light[i] > white[i]){
        white[i] = light[i];
      }
      else{
        if(light[i] < black[i]){
          black[i] = light[i];
        }
      }
    }
  }*/
  /*white[0] = 943;
  white[1] = 911;
  white[2] = 947;
  white[3] = 955;
  white[4] = 943;
  black[0] = 788;
  black[1] = 745;
  black[2] = 842;
  black[3] = 825;
  black[4] = 748;*/
  /*white[0] = 911;
  white[1] = 887;
  white[2] = 927;
  white[3] = 939;
  white[4] = 927;
  black[0] = 739;
  black[1] = 744;
  black[2] = 837;
  black[3] = 832;
  black[4] = 693;*/
  white[0] = 927;
  white[1] = 895;
  white[2] = 943;
  white[3] = 955;
  white[4] = 943;
  black[0] = 772;
  black[1] = 753;
  black[2] = 842;
  black[3] = 837;
  black[4] = 748;





  
  for(int i=0; i<5; i++){
    thresh[i] = (black[i] + white[i])/2; //Callibrated values go to thresh array
    thresh2[i] = (black[i] + 0.3*(white[i] - black[i]));
  }
  rampinit();
  claw(1500,60);
}
