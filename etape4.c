#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    unsigned long int n = 6554179; // clef publique
    unsigned long int d = 55621; // clef privée utilisée pour déchiffré
    FILE* lire;
    FILE* ecrire;
    lire = fopen("Etape4.bin","r");
    ecrire = fopen("Reponse4.txt","w");
    
    while (!feof(lire)) //tant que fread lit quelque chose la boucle continnue .
    {
        unsigned long int chiffre;
        fread(&chiffre, sizeof(unsigned long int), 1, lire);
        unsigned long int dechiffre = 1;
        for (unsigned long int i = 0; i < d; i++) 
			{//fais l'équivalent de M congru àC^d modulo n
			dechiffre = (dechiffre * chiffre) % n;
			}
        fprintf(ecrire, "%lc", (char) dechiffre);
    }
    fclose(lire);
    fclose(ecrire);
    return 0;
}
