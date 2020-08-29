#include <stdio.h>
#include "polynom.h"

//POLYNOMES
polynom * createMonome(int degree, int coeff)
{
	if(degree <0) //si le degre est negatif demander a ce qu un degre positif soit entre
	{
		printf("Please enter a positive value for the monome degree");
		return NULL;
	}
	else{ //on peut executer la fonction et creer le monome
		polynom * P;
		P = (polynom *)malloc(sizeof(polynom));
		P->coeff = coeff;
		P->degree = degree;
		P->nextterm = NULL;
		return P;
	}
}

polynom * addMonome(polynom * polynome, int degree, int coeff)
{
	if(polynome == NULL){return createMonome(degree,coeff);}//si le polynome est vide on cree le monome
	else
	{
		if(degree > polynome->degree) // dans le cas ou le monome est de degre superieur au polynome on le place en tete
		{
			polynom * P = createMonome(degree,coeff);
			P->nextterm = polynome;
		}
		else{ //sinon on parcourt le polynome jusqu au terme de mm degre et soit on additionne soit on y place le monome esi le terme n existe pas
			polynom * P = polynome;
			while(P->nextterm != NULL && P->nextterm->degree > degree)
			{
				P = P->nextterm;
			}
			if(P->nextterm->degree = degree)
			{
				P->nextterm->coeff += coeff;
			}
			else
			{
				polynom * p = createMonome(degree,coeff);
				p->nextterm = P->nextterm;
				P->nextterm = p;
			}
			return polynome;
		}
	}
}

polynom * mulMonome(polynom * polynome, int degree, int coeff)
{
	polynom * P = NULL;//initialise le polynome P
	polynom * R = polynome;
	if(R == NULL)
		return NULL;
	while(R->nextterm != NULL)
	{
		P = addMonome(P, R->degree + degree, R->coeff*coeff);
		R = R->nextterm;
	}
	return P;
}

polynom * polyn_copy(polynom a) // renvoie une copie d'un polynome
{
	polynom * copy = NULL;
	polynom * P = a;
	while(P != NULL)
	{
		copy = addMonome(copy, P->degree, P->coeff);	
		P = P->nextterm;
	}
	return copy;
}

void polyn_freeMemory(polynom * a)
{
	polynom * P = a;
	while(P!=NULL)
	{
		P = a.nextterm;
		free(a);
		polynom * a = P;
	}
}

//OPERATIONS EN CORPS FINI

polynom * F_createMonome(int degree, int coeff)
{
	if(degree <0) //si le degre est negatif demander a ce qu un degre positif soit entre
	{
		printf("Please enter a positive value for the monome degree");
		return NULL;
	}
	else{ //on peut executer la fonction et creer le monome
		polynom * P;
		P = (polynom *)malloc(sizeof(polynom));
		P->coeff = coeff%CORPS;
		P->degree = degree%PHICORPS;
		P->nextterm = NULL;
		return P;
	}
}

polynom * F_addMonome(polynom * polynome, int degree, int coeff)
{
	if(polynome == NULL){return F_createMonome(degree,coeff);}//si le polynome est vide on cree le monome
	else
	{
		if(degree%PHICORPS > polynome->degree) // ici on suppose que polynome->degree est deja modulo PHICORPS sinon il faut ajouter %PHICORPS a la condition
		{
			polynom * P = F_createMonome(degree%PHICORPS,coeff%CORPS);
			P->nextterm = polynome;
		}
		else{ //sinon on parcourt le polynome jusqu au terme de mm degre et soit on additionne soit on y place le monome esi le terme n existe pas
			polynom * P = polynome;
			while(P->nextterm != NULL && P->nextterm->degree > degree%PHICORPS)
			{
				P = P->nextterm;
			}
			if(P->nextterm->degree = degree%PHICORPS)
			{
				P->nextterm->coeff += coeff%CORPS;
			}
			else
			{
				polynom * p = F_createMonome(degree,coeff);
				p->nextterm = P->nextterm;
				P->nextterm = p;
			}
			return polynome;
		}
	}
}

polynom * F_mulMonome(polynom * polynome, int degree, int coeff)
{
	polynom * P = NULL;//initialise le polynome P
	polynom * R = polynome;
	if(R == NULL)
		return NULL;
	while(R != NULL)
	{
		P = F_addMonome(P, R->degree + degree, R->coeff*coeff);//ici on ne met pas de modulo sur les parametres comme on utilise F_addMonome qui s en charge
		R = R->nextterm;
	}
	return P;
}



//OPERATIONS SUR LES POLYNOMES

polynom * polyn_add(polynom a, polynom b) //addition de polynomes
{
	polynom * P = polyn_copy(a);
	polynom * R = b;
	while(R!=NULL)
	{
		P = addMonome(P, R->degree, R->coeff);
		R = R->nextterm;
	}
	return P;
}

polynom * polyn_sub(polynom a, polynom b) //substraction de polynomes
{
	polynom * P = polyn_copy(a);
	polynom * R = b;
	while(R!=NULL)
	{
		P = addMonome(P, R->degree, (-1)*(R->coeff));
		R = R->nextterm;
	}
	return P;
}

polynom * polyn_mul(polynom a, polynom b)//multiplication de polynomes
{
	polynom * P = polyn_copy(a);
	polynom * P1 = b;
	polynom * R = NULL;
	while(P1!=NULL)
	{
		R = polyn_add(R, mulMonome(P, P1->degree, P1->coeff));
		polynom * P = polyn_copy(a);
		P1 = P1->nextterm;
	}
	return R;
}

polynom * polyn_mod(polynom a, polynom mod) //modulo par polynome
{
	if(a->coeff == 0)
	{
		a = a->nextterm;
		return polyn_mod(a, mod);
	}
	if(a->degree < mod->degree)
		return a;
	else
	{
		polynom * B = polyn_copy(mod); //a = B*Q + R
		polynom * Q = F_createMonome((a->degree - B->degree), (a->coeff * inv_mod(B->coeff)));
		B = F_polyn_mul(B,Q);
		polynom * R = F_polyn_sub(a,B);
		return polyn_mod(R,mod); //cette boucle recursive prendra fin car on retire le terme de plus grand exposant a chaque tour et les polynomes sont finis
	}
}



polynom * polyn_inv(polynom a, polynom mod); //inversion modulaire de polynomes
/*polynom * polyn_mul_scal(polynom a, int b); multiplication par un scalaire equivaut a mulMonome(polynom * = a, degree = 0, coeff = b)*/
