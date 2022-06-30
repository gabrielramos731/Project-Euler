#include<stdio.h>

int main(){

    int i, j, count_div=0, count_prime=0;

    for(i=1;;i++){
        count_div = 0;
        for(j=1; j<=i; j++){
            if(i%j == 0)
                count_div++;
                if(count_div > 2)
                    break;
        }
        if(count_div == 2)
            count_prime++;
        if(count_prime == 10001){
            printf("%d", i);
            return 1;
        }
    }
}
