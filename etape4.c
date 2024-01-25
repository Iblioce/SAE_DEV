#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int n = 6554179; // clef publique
	int d = 55621; // clef privée utilisée pour déchiffré
	FILE* lire;
	FILE* ecrire;
	char *zone_char=malloc(sizeof(char));
	lire=fopen("Etape4.bin","r");
	ecrire=fopen("Reponse4.txt","w");
	
	while(!feof(lire)){
		
		fread( &zone_char ,sizeof(char),1,lire);
		char chiffre = *zone_char;
		char dechifre = (chiffre^d)%n;
		printf("%d", dechifre);
		fwrite(&chiffre,sizeof(char),1,ecrire);
	}
	fclose(lire);
	fclose(ecrire);

    return 0;
}
