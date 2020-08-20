#include <stdio.h>

//POLYNOMES

typedef struct polynom polynom;
struct polynom
{
	int degree;
	int coeff;
	polynom * nextterm ; 

};

//OPERATIONS SUR LES MONOMES

polynom * createMonome(int deg, int coeff); //creation d un monome
polynom * addMonome(polynom * polynome, int degree, int coeff); //addition d un monome a un polynome
polynom * mulMonome(polynom * polynome, int degree, int coeff); //multiplication d un monome par un polynome
polynom * polyn_copy(polynom * a); // renvoie une copie d'un polynome
void polyn_freeMemory(polynom  * a); // free(a);

//OPERATIONS EN CORPS FINI

polynom * F_createMonome(int deg, int coeff); //creation d un monome
polynom * F_addMonome(polynom * polynome, int degree, int coeff); //addition d un monome a un polynome
polynom * F_mulMonome(polynom * polynome, int degree, int coeff); //multiplication d un monome par un polynome

//OPERATIONS SUR LES POLYNOMES

polynom * polyn_add(polynom * a, polynom * b); //addition de polynomes
polynom * polyn_sub(polynom * a, polynom * b); //substraction de polynomes
polynom * polyn_mul(polynom * a, polynom * b); //multiplication de polynomes
polynom * polyn_inv(polynom * a, polynom * mod); //inversion modulaire de polynomes
polynom * polyn_mod(polynom * a, polynom * mod); //modulo par polynome
/*polynom * polyn_mul_scal(polynom a, int b); multiplication par un scalaire equivaut a mulMonome(a,0,b)*/
