/* OLDER VERSION OF POLYNOMS. NEW ONE USES CHAINED LIST INSTEAD*/

#include <stdh.io>

//POLYNOMES

typedef struct polynom polynom;
struct polynom
{
	int degree;
	int coeff[degree+1];
};

int polmax(polynom a, polynom b); //renvoie un booleen en correlation avec le polynome de plus haut degre

//OPERATIONS SUR LES POLYNOMES

void polyn_add(polynom res, polynom a, polynom b); //addition de polynomes
void polyn_sub(polynom res, polynom a, polynom b); //substraction de polynomes
void polyn_mul(polynom res, polynom a, polynom b); //multiplication de polynomes
void polyn_inv(polynom res, polynom a, polynom mod); //inversion modulaire de polynomes
void polyn_mod(polynom res, polynom a, polynom mod); //modulo par polynome