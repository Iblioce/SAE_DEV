#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	unsigned long int n = 6554179; // clef publique
	unsigned long int d = 55621; // clef privée utilisée pour déchiffré
	FILE* lire;
	FILE* ecrire;
	char *zone_char=malloc(sizeof(char));
	lire=fopen("Etape4.bin","r");
	ecrire=fopen("Reponse4.txt","w");
	size_t  c;
	while(!feof(lire)){
		fread( &zone_char ,sizeof(char),1,lire);
		//char dechiffre = *zone_char;
		size_t dechiffre = 1;
		for(unsigned long int i=0;i<d;i++){
			//dechiffre = (dechiffre * zone_char)%d;
			dechiffre = (dechiffre * c)%d;
		}
		fprintf(ecrire, "%lc", (char) dechiffre);
		printf("%c", dechiffre);
		fwrite(dechiffre,sizeof(char),1,ecrire);
	}
	fclose(lire);
	fclose(ecrire);

    return 0;
}
