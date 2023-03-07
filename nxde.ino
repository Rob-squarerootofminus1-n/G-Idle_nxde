#define C2  65
#define C3  131
#define GH2 104
#define GH3 208
#define AH2 116
#define AH3 233 
#define C4  262
#define DH3 155
#define DH4 311
#define AH4 466
#define C5  523
#define GH4 416
#define DH5 622 
#define AH5 932 
#define C6 1046
#define G4  392
#define G5 792
#define FH4 370
#define FH5 740
#define GH5 832
#define F4  344
#define F5 688
#define A4  440
#define A5 880
#define D4  288
#define D5  576
#define G3 198
#define E4 329
#define REST 0
#define B4 494
#define CH4 277
#define CH5 554
#define E5 659
#define B2 123
#define D6 1174
#define E6 1318
#define F6 1397
#define CH6 1109
#define B5 988
#define E3 165
#define B3 247





int piezo = 8; 
int led = 7; 

volatile int beatlength = 220; 
float beatseparationconstant = 0.1;

int nxde[] = {
  A5,2, REST,64, A5,16, REST,32, GH5,8, REST,8, G5,8, REST,8, F5,4, F5,8, REST,8, E5,8, REST,8, C5,8,C5,8, 
  D5,2, REST,64, D5,32, REST,32, D5,8, REST,32, B4,8, REST,8, C5,4, REST,64, C5,-8, D5,16, E5,8, REST,8, C5,8, REST,8, 
  A4,4, E5,4, E5,4, E5,-8, D5,16, E5,-8, D5,16, E5,-8, D5,16, A4,4, A4,-8, A4,16, A4,-8, E5,4, E5,-8, D5,16, E5,-8, D5,16, E5,-8, D5,16,
  E5,-8, D5,16, A4,4, A4,4, A5,4, E5,4, G5,4, D5,4, E5,4, A4,4, C5,4, C5,-8, B4,16, A4,4, A4,-8, B4,16, C5,8, REST,8, B4,8, REST,8, A4,4, A4,-8,
  B4,16, C5,8, REST,8, B4,8, REST,4, A5,8, D5,16, D5,16, D5,16, D5,16, D5,8, D5,8, D5,1, REST,32, D5,8, D5,16, C5,16, E5,4, REST,-8, E5,8, C5,16,
  A4,16, A4,16, A4,16, C5,8, C5,8, A5,4, E3,4, REST,4, GH4,4, GH4,-8, E4,8, REST,8, A4,8, A4,8, B4,8, C5,8, B4,8, A4,8, B4,8, C5,8, B4,8, A4,8, B4,8, C5,8,
  E5,8, E5,4, REST,4, A5,8, A5,8, GH5,8, G5,8, FH5,8, F5,8, REST,4, E5,8, E5,8, E5,8, E5,8, E5,8, GH5,16, E5,-8, D5,2, REST,64, D5,8, E5,8, REST,4,
  D5,8, E5,8, D5,8, E5,8, D5,8, E5,8, G5,8, E5,-8, A2,-8, D5,4, REST,64, D5,8, E5,8, D5,8, E5,8, D5,8, E5,8, D5,8, E5,8, G5,8, E5,-8, A5,16, A5,8,
  G5,16,G5,8, F5,16,F5,8,E5,-8,A5,16, A5,8, G5,16,G5,8, F5,16,F5,8,E5,-8, A5,16, A5,8, G5,16, E5,8, A5,16, A5,8, G5,16, E5,8, E5,-8, C5,-16, A4,-16,
  B4,16, C5,16, B4,16, C5,16, B4,-8, REST,4, A5,-4, A5,8, GH5,4, G5,4, F5,4, F5,-8, F5,16, E5,4, C5,4, D5,2, REST,64, D5,4, B4,4, A4,-8, B4,32, C5,-8, B4,32,
  A4,4, B4,-8, B3,16, A5,2, A5,8, GH5,4, G5,4, F5,4, F5,-8, F5,16, E5,4, C5,4, D5,2, D5,4, B4,4, A5,16, C6,16, A5,16, E5,16, A5,16, E5,16, C5,4,
  A5,-8, G5,16, A5,4, C6,-8, C6,16, C6,4, REST,4, A5,4, C6,-8, C6,16, C6,4, REST,4, A5,4, C6,-8, C6,16, C6,4, A4,16, A4,-8, A4,16, A4,-8, B4,16,
  C5,-8, B4,16, A4,4, B4,-8, E4,16, A5,4, C6,-8, C6,16, C6,4, REST,4, A5,4, C6,-8, C6,16, C6,4, REST,4, A5,4, C6,-8, C6,16, C6,4, A4,16, A4,-8, A4,16, A4,-8, B4,16,
  C5,-8, B4,16, A4,4, B4,-8, E4,16, D4,4,



  
  };

int notes = sizeof(nxde) / sizeof(nxde[0]) / 2;

int wholenote = (90000 * 4) / beatlength;

int divider = 0, noteDuration = 0;

void setup() {
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = nxde[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; 
    }

    tone(piezo, nxde[thisNote], noteDuration*0.9);

    delay(noteDuration);
    
    
    noTone(piezo);
  }
}

void loop() {
  
}
