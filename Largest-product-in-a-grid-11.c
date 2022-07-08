#include<stdio.h>

double biggest_horizontal(double grid[20][20]);
double biggest_vertical(double grid[20][20]);
double biggest_diag_p(double grid[20][20]);
double biggest_diag_s (double grid[20][20]);

int main(){

    double bg_diag_p, bg_diag_s, bg_hor, bg_vert;
    int i, j;
    double grid[20][20] = {8, 2, 22, 97, 38, 15, 00, 40, 00, 75, 04, 05, 07, 78, 52, 12, 50, 77, 91, 8,
                        49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04, 56, 62, 00,
                        81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 03, 49, 13, 36, 65,
                        52, 70, 95, 23, 04, 60, 11, 42, 69, 24, 68, 56, 01, 32, 56, 71, 37, 02, 36, 91,
                        22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,
                        24, 47, 32, 60, 99, 03, 45, 02, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,
                        32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,
                        67, 26, 20, 68, 02, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21,
                        24, 55, 58, 05, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
                        21, 36, 23, 9, 75, 00, 76, 44, 20, 45, 35, 14, 00, 61, 33, 97, 34, 31, 33, 95,
                        78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16, 14, 9, 53, 56, 92,
                        16, 39, 05, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54, 24, 36, 29, 85, 57,
                        86, 56, 00, 48, 35, 71, 89, 07, 05, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
                        19, 80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 04, 89, 55, 40,
                        04, 52, 8, 83, 97, 35, 99, 16, 07, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
                        88, 36, 68, 87, 57, 62, 20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
                        04, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36,
                        20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 04, 36, 16,
                        20, 73, 35, 29, 78, 31, 90, 01, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54,
                        01, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 01, 89, 19, 67, 48};

    bg_hor = biggest_horizontal(grid);
    printf("\nbiggest horizontal: %.f", bg_hor);
    bg_vert = biggest_vertical(grid);
    printf("\nbiggest vertical: %.f", bg_vert);
    bg_diag_p = biggest_diag_p(grid);
    printf("\nbiggest diag: %.f", bg_diag_p);
    bg_diag_s = biggest_diag_s(grid);
    printf("\nbiggest diag secondary: %.f", bg_diag_s);
}

//encontra o maior produto horizontal
double biggest_horizontal(double grid[20][20]){
    double prod=1, bg_prod=grid[0][0]*grid[0][1]*grid[0][2]*grid[0][3];
    int i, j, k, l;

    for(i=0; i<20; i++){
        for(j=0,k=3; k<20; j++, k++){
            for(l=j; l<=k; l++)
                prod*=grid[i][l];

            if(prod>bg_prod)
                bg_prod=prod;
            prod=1;
        }
    }
    return bg_prod;
}

//encontra o maior produto vertical
double biggest_vertical(double grid[20][20]){
    int i, j;
    double grid_T[20][20];

    for(i=0; i<20; i++)
        for(j=0; j<20; j++)
            grid_T[i][j] = grid[j][i];   //transposta
        return biggest_horizontal(grid_T);   //vai retornar o vertical

}

//encontra o maior produto na diagonal 'principal'
double biggest_diag_p(double grid[20][20]){
    int i, j, k, l, cont=0;
    double prod=1, bg_prod=grid[0][0]*grid[1][1]*grid[2][2]*grid[3][3];

    for(i=0; i<=16; i++){
        for(j=0; j<=16; j++){
            for(k=i, l=j; cont!=4; k++, l++){
                prod*=grid[k][l];
                cont++;
            }
            if(prod>bg_prod)
                bg_prod=prod;

            cont=0;
            prod=1;
        }
    }
    return bg_prod;
}

//encontra o maior produto na diagonal 'secundária'
double biggest_diag_s(double grid[20][20]){
    double grid_I[20][20], bg_prod=grid[0][0]*grid[1][1]*grid[2][2]*grid[3][3];
    int i, j, k;

    for(i=0; i<20; i++)
        for(j=0, k=19; j<20; j++, k--)
            grid_I[i][j] = grid[i][k];

    return biggest_diag_p(grid_I);
}
