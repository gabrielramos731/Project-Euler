#include<stdio.h>

int main(){

    long int i; long int j;
    float sum=17;
    long int cont=0;

    for(i=1; i<2000000; i+=2){
        for(j=1; j<=i; j++){
            if(i%j == 0)
                cont++;
            if(cont > 2)
                break;
        }
        if(cont == 2)
            sum+=i;
        cont=0;
    }
    printf("%.f", sum);
}
