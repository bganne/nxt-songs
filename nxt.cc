#include <stdio.h>
#include <math.h>

#define PROGMEM
#define pgm_read_word_near(x)	(x)[0]
#define noTone(x)

static void tone(int buzzer, int freq, int duration)
{
	printf("		%i, %i, ", freq, duration);
}

static void delay(int duration)
{
	printf("%i,\n", duration);
}

extern int notes;
static void setup(void);

int main(void)
{
	printf("#define VOLUME 1\n\n"
		   "task music()\n"
		   "{\n"
		   "	/* frequency, duration, wait */\n"
		   "	short melody[] = {\n");

	setup();

	printf("	};\n"
		   "	while(true) {\n"
		   "		for (int i=0; i<%i; i+=3) {\n"
		   "			PlayToneEx(melody[i+0], melody[i+1], VOLUME, FALSE);\n"
		   "			Wait(melody[i+2]);\n"
		   "		}\n"
		   "		Wait(1000);\n"
		   "	}\n"
		   "}\n\n"
		   "task main()\n"
		   "{\n"
		   "	start music;\n"
		   "}", notes * 3);

	return 0;
}
