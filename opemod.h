/*L ensemble des fonctions ici est destine a implementer les operations sur les polynomes mais avec le module GMP
Pour l instant les polynomes ont des coeff et degres en integer ce qui ne presente pas un interet enorme en cryptographie ou l on manipule de grands nombres
*/
#include <stdio.h>
#include <gmp.h>

//OPERATIONS MODULAIRES

void fp_add(mpz_t res , mpz_t p , mpz_t q , mpz_t corps);
void fp_sub(mpz_t res , mpz_t p , mpz_t q , mpz_t corps);
void fp_mul(mpz_t res , mpz_t p , mpz_t q , mpz_t corps);
void fp_inv(mpz_t res , mpz_t p , mpz_t corps);

//MODULO POLYNOME

void modpol_add();
void modpol_sub();
void modpol_mul();
void modpol_inv();
void modpol_mod();
