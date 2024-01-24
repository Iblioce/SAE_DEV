#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char cesar(int n,char lettre,char* alphabet,char* ALPHABET) {
	int i=0;
	while (lettre!=alphabet[i] | lettre!=ALPHABET[i]) {
		i++;
		if (i==26) {
			return lettre;
		}
	}
	if (n>i) {
		i+=26;
	}
	i-=n;
	return alphabet[i];
}

int main() {
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

	lire=fopen("Etape2.bin","r");
	ecrire=fopen("Reponse2.txt","w+");
	while (!feof(lire)) {
		c=fread(zone_char,sizeof(char),1,lire);
		c=cesar(13,*zone_char,alphabet,ALPHABET);
		printf("%c", c);
		fwrite(&c,sizeof(char),1,ecrire);
	}
	fclose(lire);
	fclose(ecrire);

}
