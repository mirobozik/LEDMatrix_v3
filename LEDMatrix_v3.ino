/*
See Sprite Generator on Plunker
http://embed.plnkr.co/3VUsekP3jC5xwSIQDVHx/preview
*/
#include <MaxMatrix.h>

//PINS setup
#define PIN_DIN 8
#define PIN_CS	9
#define PIN_CLK	10

#define LED_MATRIX_COUNT 1
#define LED_MATRIX_INTENSITY 1

// Definicie spriteov
byte rect[4][10] = {
	{8, 8, B11111111, B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B11111111 },
	{8, 8, B00000000, B01111110, B01000010, B01000010, B01000010, B01000010, B01111110, B00000000 },
	{8, 8, B00000000, B00000000, B00111100, B00100100, B00100100, B00111100, B00000000, B00000000 },
	{8, 8, B00000000, B00000000, B00000000, B00011000, B00011000, B00000000, B00000000, B00000000 }
};

byte spriteRectAlt1[] = {8, 8, /*Riadok c. 1*/B11110000,B11110000,B11110000,B11110000,B00001111,B00001111,B00001111,/*Riadok c. 7*/B00001111};
byte spriteRectAlt2[] = {8, 8, B00001111,B00001111,B00001111,B00001111,B11110000,B11110000,B11110000,B11110000};

byte cube[6][10] = {
	/*cislo 1 na hracej kocke*/{8, 8, B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000},
	/*cislo 2 na hracej kocke*/{8, 8, B00000000,B00000110,B00000110,B00000000,B00000000,B01100000,B01100000,B00000000},
	/*cislo 3 na hracej kocke*/{8, 8, B00000011,B00000011,B00000000,B00011000,B00011000,B00000000,B11000000,B11000000},
	/*cislo 4 na hracej kocke*/{8, 8, B11000011,B11000011,B00000000,B00000000,B00000000,B00000000,B11000011,B11000011},
	/*cislo 5 na hracej kocke*/{8, 8, B11000011,B11000011,B00000000,B00011000,B00011000,B00000000,B11000011,B11000011},
	/*cislo 6 na hracej kocke*/{8, 8, B01100110,B01100110,B00000000,B01100110,B01100110,B00000000,B01100110,B01100110}
};
	
MaxMatrix maxMatrix(PIN_DIN, PIN_CS, PIN_CLK, LED_MATRIX_COUNT);

void setup()
{
	maxMatrix.init();
	maxMatrix.setIntensity(LED_MATRIX_INTENSITY);
}

void loop()
{
	run_rect(200);
	delay(500);
	
	run_altrect(500);
	delay(500);
	
	run_cube(2000);
	delay(500);
}

void run_rect(int delayVal)
{
	for (int r=0; r < 4; r++)
	{
		byte *t = (byte *)(rect[r]);
		// funkcia writeSprite nastavenie LED diod podla definicie v poli
		maxMatrix.writeSprite(/*int x=*/0, /*int y=*/0, /*const byte* sprite=*/t); 
		delay(delayVal);
	}
	maxMatrix.clear();
}

void run_altrect(int delayVal)
{
	maxMatrix.writeSprite(0, 0, spriteRectAlt1);
	delay(delayVal);
	maxMatrix.clear();	
	delay(delayVal);
	maxMatrix.writeSprite(0, 0, spriteRectAlt2);
	delay(delayVal);
	maxMatrix.clear();
	delay(delayVal);
}

void run_cube(int delayVal)
{
	int cubeNumber = random(0, 6);
	byte *sprite = (byte *)(cube[cubeNumber]);
	maxMatrix.writeSprite(0, 0, sprite);
	delay(delayVal);
}
