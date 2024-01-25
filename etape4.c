#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main() {
	long int n = 6554179; // clef publique
	long int e = 689149; //clef publique
	long int d = 55621; // clef privée
	char alphabet[26];
	char ALPHABET[26];
	char maj='A';
	char c='a';
	int i=0;
	FILE* lire;
	FILE* ecrire;
	char *zone_char=malloc(sizeof(char));
	alphabet[i]=c;
	ALPHABET[i]=maj;
	while (c!='z') {
		c++;
		i++;
		maj++;
		alphabet[i]=c;
		ALPHABET[i]=maj;
	}

	lire=fopen("Etape4.bin","r");
	ecrire=fopen("Reponse4.txt","w+");
	
	int b=pow(c,d)
        c = (b%n);
	fwrite(&c,sizeof(char),1,ecrire);
	}
	fclose(lire);
	fclose(ecrire);
}
