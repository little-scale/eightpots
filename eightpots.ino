const int order[] = {4, 5, 6, 7, 3, 2, 1, 0, };
int pots[8];
int data; 

void setup() {
  analogReadResolution(7); 
  analogReadAveraging(20);

}

void loop() {
  for(int i = 0; i < 8; i ++) {
    data = analogRead(A0 + i);
    if(data != pots[i]) {
      pots[i] = data; 
      usbMIDI.sendControlChange(order[i] + 1, 127 - data, 1);
      delay(10); 
    }
  }

}
