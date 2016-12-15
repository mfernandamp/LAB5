//Laboratorio número 5

//Librerias

#include <gmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




int main(int argc, char *argv[]){
	
	FILE *file;
	mpz_t n, n1, a, B, tmp, GCD, aux, sol;
	clock_t inicio, fin; // Se crea variable 'clock_t' para calcular el tiempo de ejecúción del programa.
	inicio=clock();
	float tiempo = 0;
	mpz_init_set_str(n,argv[1],10);
	unsigned long long int aleatorio;

	//Se inician las variables en 0
	mpz_init(n1);
	mpz_init(a);
	mpz_init(B);
	mpz_init(tmp);
	mpz_init(GCD);
	mpz_init(aux);
	mpz_init(sol);
	gmp_randstate_t state;
	
		
	if (mpz_probab_prime_p(n,30) == 0){
		do{
			srand(time(0));
			aleatorio = rand(); //Entrega un número aleatorio
			gmp_randinit_mt (state);
			gmp_randseed_ui(state,aleatorio);
			mpz_sub_ui(tmp,n,1);
			mpz_urandomm(a, state, tmp);
			mpz_gcd(GCD,a,n);
			mpz_set_ui(B,2);
			mpz_powm(a, a, B, n);
			mpz_sub_ui(aux,a,1);
			mpz_gcd(n1,aux,n);
			while (mpz_cmp_ui(n1,1) == 0){
				mpz_add_ui(B,B,1);
				mpz_powm(a, a, B, n);
				mpz_sub_ui(aux,a,1);
				mpz_gcd(n1,aux,n);	
			}	
		}while(mpz_cmp(n1,n) == 0);
	}
	else{
			printf("N es un número primo.");
			return 0;
		}
		
	printf("El factor n1 es: ");
	gmp_printf("%Zd \n",n1);
	printf("El factor n2 es: ");
	mpz_cdiv_q(sol,n,n1);
	gmp_printf("%Zd \n",sol);
	printf("El valor de B es : ");
	gmp_printf("%Zd \n",B);	
	
	fin=clock();
	tiempo = (fin-inicio)/(double)CLOCKS_PER_SEC;
	printf("El tiempo de ejecución fue de: %f \n",tiempo); 
	printf("hola\n");
	file = fopen("lab05exp.txt", "a");
	if(file == NULL)
	{
		printf("Error al abrir el archivo\n")
;	}
    printf("hola1\n");
    mpz_out_str(file, 10, n);
    fprintf(file, "\t");
    mpz_out_str(file, 10 ,  B);
    fprintf(file,"\t %F \n",tiempo);
    fclose(file);

	//Se libera la memoria de las variables
	mpz_clear(n);
	mpz_clear(n1);
	mpz_clear(a);
	mpz_clear(B);
	mpz_clear(tmp);
	mpz_clear(GCD);
	mpz_clear(aux);
	mpz_clear(sol);
	
	return 0;
	
	
}

