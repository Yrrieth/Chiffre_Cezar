#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

void chiffre(char *s) {
    int c;  // Cle
    int d;  // Difference du numero ASCII de la cle et de la reference
    char *r = malloc(strlen(s)*sizeof(char));
    assert(r);
    int i, tmp;  // i = compteur; tmp = variable temporaire

    i = 0;
    do {
        i = 0;
        printf("Entrez la cle : a -> ?\n");
        c = getchar();
        printf("Cle : a -> %c\n", c);
        if (c >= 97 && c <= 122) {
            i = 1;
        } else {
            printf("\nLa cle doit etre une lettre minuscule.\n\n");
            c = 0;
        }
    } while(!i);

    d = c - 'a';
    printf("%d lettre(s) de difference(s)\n", d);

    for(i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 32 && s[i] <= 64) || (s[i] >= 91 && s[i] <= 96) || (s[i] >= 123 && s[i] <= 126)) // Tous le reste
            r[i] = s[i];

        if (s[i] >= 97 && s[i] <=  122) {  // Minuscule
            if (s[i] + d > 122) {  // Si on depasse 'z'
                tmp = s[i] + d - 122;  // Nombre de lettre qui reste a parcourir
                tmp = tmp - 1 + 'a';  // On revient a 'a' et on additione avec le reste a parcourir
                r[i] = tmp;
            } else {
                r[i] = s[i] + d;
            }
        }

        if (s[i] >= 65 && s[i] <=  90) {  // Majuscule
            if (s[i] + d > 90) {
                tmp = s[i] + d - 90;
                tmp = tmp - 1 + 'A';
                r[i] = tmp;
            } else {
                r[i] = s[i] + d;
            }
        }

        printf(" %c -> %c ||", s[i], r[i]);
    }
    r[i] = '\0';

    printf("\n\nAncienne phrase : %s \n", s);
    printf("Nouvelle phrase : %s \n", r);
    free(s);
    free(r);
    return;
}

char * entree() {
    char *s, *p;
    s = malloc(100*sizeof(char));
    assert(s);
    p = s;
    printf("Entrez la phrase a transcrire :\n");
    do {
        *p = getchar();
    } while (*p++ != '\n');
    *--p = '\0';  //  On revient dans la case precedente car dans celle-ci il y avait la place alloue pour '\n'
                  //  et on coupe la chaine
    printf ("La phrase est %s\n", s);
    return s;
}

void dechiffre(char *s) {
    int c;  // Cle
    int d;  // Difference du numero ASCII de la cle et de la reference
    char *r = malloc(strlen(s)*sizeof(char));
    assert(r);
    int i, tmp;  // i = compteur; tmp = variable temporaire

    i = 0;
    do {
        i = 0;
        printf("Entrez la cle : a <- ?\n");
        c = getchar();
        printf("Cle : a <- %c\n", c);
        if (c >= 97 && c <= 122) {
            i = 1;
        } else {
            printf("\nLa cle doit etre une lettre minuscule.\n\n");
            c = 0;
        }
    } while(!i);

    d = c - 'a';
    printf("%d lettre(s) de difference(s)\n", d);

    for(i = 0; s[i] != '\0'; i++) {
        if ((s[i] >= 32 && s[i] <= 64) || (s[i] >= 91 && s[i] <= 96) || (s[i] >= 123 && s[i] <= 126)) // Tous le reste
            r[i] = s[i];

        if (s[i] >= 97 && s[i] <=  122) {  // Minuscule
            if (s[i] - d < 97) {  // Si on depasse 'a'
                tmp = s[i] - d - 97;  // Nombre de lettre qui reste a parcourir
                tmp = tmp + 1 + 'z';  // On revient a 'z' et on soustrait avec le reste a parcourir (ici, tmp est negative)
                r[i] = tmp;
            } else {
                r[i] = s[i] - d;
            }
        }

        if (s[i] >= 65 && s[i] <=  90) {  // Majuscule
            if (s[i] - d > 65) {
                tmp = s[i] - d - 65;
                tmp = tmp + 1 + 'Z';
                r[i] = tmp;
            } else {
                r[i] = s[i] - d;
            }
        }

        printf(" %c <- %c ||", s[i], r[i]);
    }
    r[i] = '\0';

    printf("\n\nAncienne phrase : %s \n", s);
    printf("Nouvelle phrase : %s \n", r);
    free(s);
    free(r);
    return;
}

void vider() {  // Vide le buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void choix() {
    char *s;
    int i = 1;
    char c;
    int n;

    printf("----- Chiffre de Cezar -----\n");
    while(i) {
        printf("Que souhaitez-vous faire ?\n");
        printf("1 : Transcrire une phrase a l'aide d'une cle. (Chiffrer une phrase)\n");
        printf("2 : Retrouver une phrase grace a une cle. (Dechiffrer une phrase)\n");
        printf("Tapez 1 ou 2:\n");
        
        scanf("%d", &n);

        if (n == 1) {
            vider();
            s = entree();
            chiffre(s);
            i = 0;
        } else if (n == 2) {
            vider();
            s = entree();
            dechiffre(s);
            i = 0;
        } else {
            printf("Erreur, veuillez ressaisir une commande. \n\n");
            vider();
        }
    }
}

int main() {
    //char *s = "Hello world, today, I'm going to draw a better drawing !";
    choix();

    return 0;
}
