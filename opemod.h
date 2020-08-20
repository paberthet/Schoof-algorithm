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
