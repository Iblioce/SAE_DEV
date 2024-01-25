#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

long long mod_pow(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

long long rsa_decrypt(long long ciphertext, long long d, long long n) {
    return mod_pow(ciphertext, d, n);
}


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
	
	while(!feof(lire)){
		fread( *zone_char ,sizeof(char),1,lire);
		long double charactere = &zone_char;
		long int chiffrement = pow (charactere,d);
		int dechiffrement = (chiffrement%n);
		printf("%d", dechiffrement);
		fwrite(&c,sizeof(char),1,ecrire);
	}
	fclose(lire);
	fclose(ecrire);

	long long n = 6554179; // Module (partie publique de la clé)
    long long d = 55621;   // Clé privée

    // Message chiffré que vous souhaitez déchiffrer
    long long ciphertext = "aslkahjda";

    // Déchiffrement
    long long decrypted_message = rsa_decrypt(ciphertext, d, n);

    // Affichage du résultat
    printf("Message déchiffré : %lld\n", decrypted_message);

    return 0;
}
