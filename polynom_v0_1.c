#include <stdh.io>
#include "polynom_v0_1.h"

//POLYNOMES

int polmax(polynom a, polynom b)
{
	if(a.degree > b.degree){return 1;}
	else {return 0;}

}


//OPERATIONS SUR LES POLYNOMES

void polyn_add(polynom res, polynom a, polynom b) //addition de polynomes
{
	if(polmax(a,b))
	{
		res = a;
		for(int i = 0, i < b.degree+1, i++)
			res.coeff[i] = a.coeff[i] + b.coeff[i];
	}
	else
	{
		res = b;
		for(int i = 0, i < a.degree + 1, i++)
			res.coeff[i] = a.coeff[i] + b.coeff[i];
	}

}

void polyn_sub(polynom res, polynom a, polynom b); //substraction de polynomes
{
	if(polmax(a,b))
	{
		res = a;
		for(int i = 0, i < b.degree+1, i++)
			res.coeff[i] = a.coeff[i] - b.coeff[i];
	}
	else
	{
		res = b;
		for(int i = 0, i < a.degree + 1, i++)
			res.coeff[i] = a.coeff[i] - b.coeff[i];
		for(int i = a.degree+1 , i< res.degree + 1, i++)
			res.coeff[i] = -res.coeff[i];
	}

}

void polyn_mul(polynom res, polynom a, polynom b); //multiplication de polynomes
void polyn_inv(polynom res, polynom a, polynom mod); //inversion modulaire de polynomes
void polyn_mod(polynom res, polynom a, polynom mod); //modulo par polynome