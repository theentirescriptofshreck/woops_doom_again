bool* byteBool(byte in){
  byte i;
  float tmp = sqrt(in);
  bool* out[8];
  for(i=1;i<=8;i++){
    if(tmp/sqrt(i)>=1){
      out[i] = true;
      tmp -= sqrt(i);
    }else{
      out[i] = false;
    }
  }
  return out;
}
#define pix 1
#define sound_channel 4
void setSerialPins(){
  pinMode(1,INPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}
void sendSiginals(byte* in[7]){
  byte i;
  byte a;
  digitalWrite(4,HIGH);
  for(i=1;i<=7;i++){
    bool* currentByte[8] = byteBool(in[i]);
    analogWrite(3,((byte)(map(i,0,7,0,256))));
    for(a=1;a<=9;a++){
      analogWrite(5,((byte)(map(a,0,9,0,256))));
      if(a!=9){
        bool out = currentByte[a];
        if(out){
          digitalWrite(2,HIGH);
        }else{
          digitalWrite(2,LOW);
        }
      }
    }
  }
  digitalWrite(4,LOW);
}
