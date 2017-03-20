#include "wave.h"
#include <stdio.h>
#include <math.h>

//this program will open a wave file, and display WAV header info 
int main(int argc, char *argv[])
{
	FILE *fp;
	WAVHDR myhdr;
	int answer;
	if (argc != 2){
		printf("Usage : %s wav_file\n",argv[0]);
		return -1;
	}
	fp = fopen(argv[1], "r");
	if (fp==NULL)
	{
		printf("cant open this file %s\n", argv[1]);
		return -1;
	}
	fread(&myhdr, sizeof(myhdr),1,fp);
	displayWAVHDR(myhdr);
	fclose(fp);
	printf("do you want to generate a test tone ? 1: yes , 0 : No \n");
	scanf("%d",&answer);
	if (answer == 1  ) testTone(1000, 5);
}
void  testTone( int freq, double d)
{
	FILE *fp;
	int i;
	WAVHDR h;
	short int sample;
	fp = fopen("testtone.wav","w");
	fillID("RIFF", h.ChunkID);
	fillID("WAVE",h.Format);
	fillID("fmt ", h.SubChunk1ID);
	h.SubChunk1Size = 16;
	h.AudioFormat = 1;
	h.NumChannels = 1;
	h.SampleRate = SAMPLE_RATE;
	h.BitsPerSample = 16;
	h.ByteRate = SAMPLE_RATE * h.NumChannels * (h.BitsPerSample/8);
	h.BlockAlign= h.NumChannels * (h.BitsPerSample/8);
	fillID("data", h.SubChunk2ID);
	h.SubChunk2Size = (int)h.ByteRate * d;
	h.ChunkSize = h.SubChunk2Size + 36;
	fwrite(&h, sizeof(h),1,fp);
	for ( i=0; i<d*SAMPLE_RATE; i++)
	{
		sample = 32768*sin(2*PI*freq*i/SAMPLE_RATE);
		fwrite(&sample, sizeof(sample), 1, fp);
	} 
}
void displayWAVHDR(WAVHDR hdr)
{
	double duration;
	printf("Chunk ID"); printID(hdr.ChunkID);
	printf("Chunk Size: %d\n",hdr.ChunkSize);
	printf("Format : "); printID(hdr.Format);
	printf("Subchunk1 ID :");printID(hdr.SubChunk1ID);
	printf("SubChunk1 Size : %d\n", hdr.SubChunk1Size);
	printf("Audio Format : %d\n", hdr.AudioFormat);
	printf("Num of Channels ; %d\n",hdr.NumChannels);
	printf("Sample Rate: %d\n", hdr.SampleRate);
	printf("Byte Rate: %d\n",hdr.ByteRate);
	printf("Block Align %d\n", hdr.BlockAlign);
	printf("Bits Per Sample: %d\n", hdr.BitsPerSample);
	printf("Subchunk2 ID "); printID(hdr.SubChunk2ID);
	printf("SubChunk2 Size : %d\n",hdr.SubChunk2Size);
	duration=(double)hdr.SubChunk2Size/hdr.ByteRate;
	printf("duration of Audio %.3f\n",duration);
}
void printID(char id[])
{
	int i;
	for (i=0; i<4;i++)
		putchar(id[i]);
	printf("\n");
}
void fillID( const char *s, char d[])
{
	int i;
	for (i=0; i<4;i++)  d[i]=*s++;
}
