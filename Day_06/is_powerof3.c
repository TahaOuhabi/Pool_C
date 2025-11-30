#include <stdio.h>
#include <stdbool.h>

bool verifie_puissance3(int valeur) {
    if(valeur< 1)return true;
    while(valeur%3 ==0) valeur /= 3;
    return valeur==1;
}
int main(void) {
    int nombre;
    printf("Saisir un entier : \n");
    scanf("%d", &nombre);
    if(verifie_puissance3(nombre)) printf("%d est une puissance de 3\n", nombre);
    else printf("%d n'est pas une puissance de 3\n", nombre);
    return 0;
}
