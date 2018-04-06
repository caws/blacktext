#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int main(){

int numStrings, ponteiroTexto, i, i2, pPos = 8, fPos = 0, pos = 0, inipos=0, k, hue;
unsigned char buffer[1]; char *aux; buffer[0] = ' ';
char str[6000];

FILE *mainuk = fopen("MainUK.bin", "rb");
FILE *novomainuk = fopen("MainUKnovo.bin", "wb");
FILE *arquivotxt = fopen("MainUK.txt", "r");
FILE *arquivovls = fopen("MainUKvls.txt", "r");

fseek(mainuk, pPos, SEEK_SET);
fread(&numStrings,1,sizeof(long),mainuk);
pPos += 8;

printf("Num linhas: %d\n", numStrings);

inipos = (numStrings * 4) + 0x10;

//inserindo textos

	for (i = 0; i < numStrings; i++){
		fseek(novomainuk, pPos, SEEK_SET);
		fwrite(&inipos,1, sizeof(long), novomainuk);
		pPos += 4;
		
		fseek(novomainuk, inipos, SEEK_SET);
		
		for (i2 = 0; i2 < 4; i2++){
			fgets (str, 60, arquivovls);
			printf("%s", str);
			k = atoi(str);
			fwrite(&k, 1,1, novomainuk);
		}
		fgets (str, 1000, arquivotxt);
		printf("%s", str);
		inipos +=4;

		//escrever strings aqui
		for (i2=0; i2 < strlen(str)-1; i2++){
			if (str[i2] == '|'){
				hue = strtol(&str[i2+1], NULL, 16);
		   		fwrite(&hue, 1,1, novomainuk);				
				i2 += 2;
			}
			else
			{
	   		fwrite(&str[i2+pl], 1,1, novomainuk);	
			}

			inipos++;		
		}
		inipos +=3;

	buffer[0] = ' ';
	fprintf(arquivotxt, "\n");
	}

return 0;
}


