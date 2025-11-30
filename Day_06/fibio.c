#include <stdio.h>
long long suite_rapide(int index, long long val1, long long val2) {
    if(index == 0) return val1;
    return suite_rapide(index - 1, val2, val1 + val2);
}
long long calcul_suite(int index) {
    return suite_rapide(index, 0, 1);
}
int main(void) {
    int nombre;
    printf("saisir un nombre : \n");
    scanf("%d", &nombre);
    printf("F(%d) = %lld\n", nombre, calcul_suite(nombre));
    return 0;
}
