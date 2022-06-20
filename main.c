# include "fmpz_poly.h"
# include "time.h"
# include "flint.h"
# include "stdio.h"

int main(){
    fmpz_poly_t x , y, z ;
    //char* s="x";


    fmpz_poly_init ( x );
    fmpz_poly_init ( y );
    fmpz_poly_init ( z ) ;
    //fmpz_poly_set_coeff_ui (x , 3 , 5);
    //fmpz_poly_set_coeff_si (x , 0 , -1);
    //coeff = fmpz_mat_entry(M,0,0)
    //fmpz_poly_set_str(x,"2  -1 2");
    flint_rand_t state;
    slong len = 512; // polynomial of degree 511
    mp_bitcnt_t bits = 15;// each coefficient has < 15 bits
    int round = 500;

    char *file = "out_512_500_3.txt";
    FILE *fp = fopen(file, "w");

    if (fp == NULL)
    {
        printf("Error opening the file %s", file);
        return -1;
    }
    
    fprintf(fp, "Karatsuba,SS,Optimized\n");

    clock_t begin, end;

    //flint_randinit(state);
    for (int i=0; i<round; i++){
        fmpz_poly_randtest_not_zero(x, state, len, bits);
        fmpz_poly_randtest_not_zero(y, state, len, bits);

        //Karatsuba
        begin = clock();
        fmpz_poly_mul_karatsuba(z, y, x);
        
        end = clock();
        fprintf(fp, "%5.7f,", (double) (end-begin)/CLOCKS_PER_SEC);
        //fmpz_poly_print_pretty ( z,s ); printf ( "\n" );

        //Schonhage-Strassen (FFT)
        begin = clock();
        fmpz_poly_mul_SS(z, y, x);
        
        end = clock();
        fprintf(fp, "%5.7f,", (double) (end-begin)/CLOCKS_PER_SEC);

        //Optimized
        begin = clock();
        fmpz_poly_mul(z, y, x);
        
        end = clock();
        fprintf(fp, "%5.7f\n", (double) (end-begin)/CLOCKS_PER_SEC);
    }

    fclose(fp);
    
    //flint_randclear(state);
    fmpz_poly_clear ( x );
    fmpz_poly_clear ( y ); 
    fmpz_poly_clear ( z );


}