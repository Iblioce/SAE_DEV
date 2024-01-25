#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

int main() {
	long int n = 6554179; // clef publique
	long int d = 55621; // clef privée utilisée pour déchiffré
	int i = 0 ;
	char alphabet[26];
	char ALPHABET[26];
	char maj='A';
	char c='a';
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
	long int chiffrement = pow (c,d);
	c = (chiffrement%n);
	while(!feof(lire)){
		fread( *zone_char ,sizeof(char),1,lire)
		printf("%d",chiffrement);
		fwrite(&c,sizeof(char),1,ecrire);
	}
	fclose(lire);
	fclose(ecrire);
}
