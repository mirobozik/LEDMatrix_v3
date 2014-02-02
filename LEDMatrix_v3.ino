/*
See Sprite Generator on Plunker
http://embed.plnkr.co/3VUsekP3jC5xwSIQDVHx/preview
*/
#include <MaxMatrix.h>
#include <avr/pgmspace.h>

//PINS setup
#define PIN_DIN 8
#define PIN_CS	9
#define PIN_CLK	10

#define LED_MATRIX_COUNT 1
#define LED_MATRIX_INTENSITY 1

byte rect[4][10] = {
	{8, 8, B11111111, B10000001, B10000001, B10000001, B10000001, B10000001, B10000001, B11111111 },
	{8, 8, B00000000, B01111110, B01000010, B01000010, B01000010, B01000010, B01111110, B00000000 },
	{8, 8, B00000000, B00000000, B00111100, B00100100, B00100100, B00111100, B00000000, B00000000 },
	{8, 8, B00000000, B00000000, B00000000, B00011000, B00011000, B00000000, B00000000, B00000000 }
};

byte spriteRectAlt1[] = {8, 8, B11110000,B11110000,B11110000,B11110000,B00001111,B00001111,B00001111,B00001111};
byte spriteRectAlt2[] = {8, 8, B00001111,B00001111,B00001111,B00001111,B11110000,B11110000,B11110000,B11110000,};

byte cube[6][10] = {
	{8, 8, B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000},
	{8, 8, B00000000,B00000110,B00000110,B00000000,B00000000,B01100000,B01100000,B00000000},
	{8, 8, B00000011,B00000011,B00000000,B00011000,B00011000,B00000000,B11000000,B11000000},
	{8, 8, B11000011,B11000011,B00000000,B00000000,B00000000,B00000000,B11000011,B11000011},
	{8, 8, B11000011,B11000011,B00000000,B00011000,B00011000,B00000000,B11000011,B11000011},
	{8, 8, B01100110,B01100110,B00000000,B01100110,B01100110,B00000000,B01100110,B01100110}						
};
	
		
MaxMatrix maxMatrix(PIN_DIN, PIN_CS, PIN_CLK, LED_MATRIX_COUNT);

void setup()
{
	maxMatrix.init();
	maxMatrix.setIntensity(LED_MATRIX_INTENSITY);
}

void loop()
{
	effect_3(2000);
}

void effect_1(int delayVal)
{
	for (int r=0; r < 4; r++)
	{
		byte *t = (byte *)(rect[r]);
		maxMatrix.writeSprite(0, 0, t);
		delay(delayVal);
	}
	maxMatrix.clear();
}

void effect_2(int delayVal)
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

void effect_3(int delayVal)
{
	int cubeNumber = random(0, 6);
	byte *sprite = (byte *)(cube[cubeNumber]);
	maxMatrix.writeSprite(0, 0, sprite);
	delay(delayVal);
}
