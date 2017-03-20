/* this header file contains wave header information as a struct
 * it also contains neccesary constant definitions , and function
 * prototypes used in this project*/
typedef struct {
	char ChunkID[4];
	int ChunkSize;
	char Format[4];
	char SubChunk1ID[4];
	int SubChunk1Size;
	short int AudioFormat;
	short int NumChannels;
	int SampleRate;
	int ByteRate;
	short int BlockAlign;
	short int BitsPerSample;
	char SubChunk2ID[4];
	int SubChunk2Size;
}WAVHDR;
//#define DEBUG
#define PI 3.14
#define SAMPLE_RATE 16000
// function prototypes
void displayWAVHDR(WAVHDR hdr);
void printID(char *);
void fillID(const char *,char [] );
void testTone(int freq, double duration);
void displayWAVdata(short int []);
