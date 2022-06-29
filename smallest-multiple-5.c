#include<stdio.h>

int main(){

    int i, j, cont;

    for(i=20;;i++){
        cont=0;
        for(j=1; j<=20; j++){
            if(i%j != 0)
                break;
            if(i%j == 0)
                cont++;
        }
        if(cont == 20){
            printf("%d", i);
            return 1;
        }
    }
}
