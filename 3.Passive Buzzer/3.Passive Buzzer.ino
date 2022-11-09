// int tonepin = 3;  // Set the Pin of the buzzer to the digital D3
// void setup() {
//   pinMode(tonepin, OUTPUT);  // Set the digital IO pin mode to output
// }
// void loop() {
//   unsigned char i, j;
//   while (1) {
//     for (i = 0; i < 80; i++)  // output a frequency sound
//     {
//       digitalWrite(tonepin, HIGH);  // Sound
//       delay(1);                     // Delay 1ms
//       digitalWrite(tonepin, LOW);   // No sound
//       delay(1);                     // Delay 1ms
//     }
//     for (i = 0; i < 100; i++)  // output sound of another frequency
//     {
//       digitalWrite(tonepin, HIGH);  // Sound
//       delay(2);                     // delay 2ms
//       digitalWrite(tonepin, LOW);   // No sound
//       delay(2);                     // delay 2ms
//     }
//   }
// }


#define NTD0 -1
#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556

#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196

#define NTDL5 221
#define NTDL6 248
#define NTDL7 278

#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 112
// List all D-tuned frequencies


#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.25
#define SIXTEENTH 0.625
// List all beats
int tune [] = // List each frequency according to the notation
{
NTD3, NTD3, NTD4, NTD5,
NTD5, NTD4, NTD3, NTD2,

NTD1, NTD1, NTD2, NTD3,
NTD3, NTD2, NTD2,
NTD3, NTD3, NTD4, NTD5,
NTD5, NTD4, NTD3, NTD2,
NTD1, NTD1, NTD2, NTD3,
NTD2, NTD1, NTD1,
NTD2, NTD2, NTD3, NTD1,
NTD2, NTD3, NTD4, NTD3, NTD1,
NTD2, NTD3, NTD4, NTD3, NTD2,
NTD1, NTD2, NTDL5, NTD0,
NTD3, NTD3, NTD4, NTD5,
NTD5, NTD4, NTD3, NTD4, NTD2,
NTD1, NTD1, NTD2, NTD3,
NTD2, NTD1, NTD1
};
float durt [] = // List the beats according to the notation
{
1,1,1,1,
1,1,1,1,
1,1,1,1,
1 + 0.5,0.5,1 + 1,
1,1,1,1,
1,1,1,1,
1,1,1,1,
1 + 0.5,0.5,1 + 1,
1,1,1,1,
1,0.5,0.5,1,1,
1,0.5,0.5,1,1,
1,1,1,1,
1,1,1,1,
1,1,1,0.5,0.5,
1,1,1,1,
1 + 0.5,0.5,1 + 1,
};
int length;
int tonepin = 3; // Use interface 3
void setup ()
{
pinMode (tonepin, OUTPUT);
length = sizeof (tune) / sizeof (tune [0]); // Calculate length
}
void loop ()
{
  for (int x = 0; x <length; x ++)

  {
tone (tonepin, tune [x]);
delay (350* durt [x]); // This is used to adjust the delay according to the beat,350 can be adjusted by yourself. 
noTone (tonepin);
}
delay (2000); // delay 2S
}