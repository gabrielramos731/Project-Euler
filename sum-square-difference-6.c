#include<stdio.h>

int main(){

    int sum_sqr, sqr_sum, sum, i;
    for(i=1; i<=100; i++){
        sum_sqr += (i*i);
        sum+=i;   //sum of first 100 naturals
    }
    sqr_sum = sum*sum;
    printf("\ndif: %d", sqr_sum-sum_sqr);
}
