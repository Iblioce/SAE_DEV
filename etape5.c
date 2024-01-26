#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int premier(long int valeur) {
  if (valeur <= 1) return 0; // 0 et 1 ne sont pas premiers
  for (int i = 2; i * i <= valeur; i++) { //la fonction renvoie 0 si valeur n'est pas premier
    if (valeur % i == 0) return 0;
  }
  return 1;
}

int PGCD(long int a, long int b, long int *u, long int *v) {
  if (b == 0) {// si B égale 0 la division est impossible
    *u = 1;
    *v = 0;
    return a;
  }
  long int u1, v1;// coefficients
  long int euclide = PGCD(b, a % b, &u1, &v1);// b et a sont inversé car on remplace a par b puis on enleve x fois b de A qu'on met en diviseur
  *u = v1;
  *v = u1 - (a / b) * v1;
  return euclide;
}


int D_valeur(long int e, long int n) {
  long int u, v;
  //algorithme d'euclide étandue
  for (long int p = 2; p <= n; p++) {
    if (n % p == 0 && premier(p)) {
      long int q = n / p;
      if (premier(q)) {
        long int phi_de_n = (p - 1) * (q - 1);
        PGCD(phi_de_n, e, &u, &v);
        long int d = v;// si v est positif alors D égale V sinon D égale phi_de_n - v. 
        if (v < 0) d = (phi_de_n - v); 
        return d;
      }
    }
  }    
}

int main() {
    long int e = 5625943;
    long int n = 2158731;
    FILE* lire;
    FILE* ecrire;
    lire=fopen("Etape5.bin","r");
    ecrire=fopen("Reponse5.txt","w");
    long int d = D_valeur(e, n);
    long int c;
    while (!feof(lire)) //tant que fread lit quelque chose la boucle continnue .
    {
        unsigned long int chiffre;
        fread(&chiffre, sizeof(unsigned long int), 1, lire);
        unsigned long int dechiffre = 1;
        for (unsigned long int i = 0; i < d; i++) {//fais l'équivalent de M congru àC^d modulo n
            dechiffre = (dechiffre * chiffre) % n;
        }
        fprintf(ecrire, "%lc", (char) dechiffre);
    }
    fclose(lire);
    fclose(ecrire);
    return 0;
}
