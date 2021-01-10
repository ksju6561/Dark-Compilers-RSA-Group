#ifndef _DARK_COMPILER_H
	#include <stdio.h>
	#include <string.h>

	#include <openssl/bn.h>
	#include <openssl/sha.h>
	#include <gmp.h>
	#include <math.h>
	#include <flint/fmpz.h>

	typedef struct{
		int security_level;
		fmpz_t G;
		fmpz_t q;
		fmpz_t p;
		fmpz_t g;
	}_struct_pp_;

	typedef struct{
		fmpz_t C;
	}_struct_commit_;

	typedef struct{
		fmpz_t* Fx;
		int d;
	}_struct_poly_;

	typedef struct{
		fmpz_t alpha;
		fmpz_t yL;
		fmpz_t yR;
		fmpz_t POE_proof;
		_struct_commit_ CL;
		_struct_commit_ CR;
	}_struct_proof_;

	int pp_init(_struct_pp_* pp);
	int pp_clear(_struct_pp_* pp);
	int KeyGen_Class_setup( _struct_pp_* pp, const int lamda, const int logD);
	
	int commit_init(_struct_commit_* cm);
	int commit_clear(_struct_commit_* cm);
	int commit_new(_struct_commit_* cm, _struct_pp_ pp, _struct_poly_ poly);
	int commit_new_precom(_struct_commit_* cm, _struct_pp_ pp, _struct_poly_ poly);

	int pf_init(_struct_proof_ *pf);
	int pf_clear(_struct_proof_ *pf);
	int Eval_prover(_struct_pp_* pp, _struct_commit_* cm, _struct_poly_* poly, int testbit);
	int Eval_verify(_struct_pp_* pp, _struct_commit_* cm, _struct_poly_* poly);
	
    #define _DARK_COMPILER_H
#endif

