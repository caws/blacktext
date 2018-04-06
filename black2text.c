#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int main(){

int numStrings, ponteiroTexto, i, i2, pPos = 8, fPos = 0, pos = 0, k;
unsigned char buffer[1]; char *aux; buffer[0] = ' ';

FILE *mainuk = fopen("MAINGE.BIN", "rb");
FILE *arquivotxt = fopen("Mainge.txt", "w+");
FILE *arquivovls = fopen("MainUKvlsge.txt", "w+");

fseek(mainuk, pPos, SEEK_SET);
fread(&numStrings,1,sizeof(long),mainuk);
pPos += 8;

printf("Num linhas: %d\n", numStrings);
//extraindo textos

	for (i = 0; i < numStrings; i++){
		fseek(mainuk, pPos, SEEK_SET);
		fread(&ponteiroTexto,1, sizeof(long), mainuk);
		pPos += 4;
		
		fseek(mainuk, ponteiroTexto, SEEK_SET);
		
		for (i2 = 0; i2 < 4; i2++){
			fread(&k,1,1,mainuk);
			fprintf(arquivovls, "%d\n", k);
		}

		while (buffer[0] != 0){
			fread(buffer,1,1,mainuk);
			if (buffer[0] != 0){
			 	if ((buffer[0] == 0x0D) || (buffer[0] == 0x0A)){
					fprintf(arquivotxt, "|%hhx|", buffer[0]);	
				}
				else
				{
					fprintf(arquivotxt, "%c", buffer[0]);
				}
			}
		}
	buffer[0] = ' ';
	fprintf(arquivotxt, "\n");
	}

return 0;

}
