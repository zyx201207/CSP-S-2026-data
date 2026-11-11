#include<bits/stdc++.h>
using namespace std;

int R1, R2, X1, X2, R3, X3;
char R, X;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d%d%c%d%d%c", &R1, &R2, &R, &X1, &X2, &X);
    R3 = int(R) - 64, X3 = int(X) - 64;
    if(R1 == X1){
        printf("1");
    } else{
        printf("0000");
        return 0;
    } if(R2 == X2){
        printf("1");
    } else{
        printf("000");
        return 0;
    } if(!((R3 == 3 && X3 == 4) || (R3 == 4 && X3 == 3))){
        printf("1");
    } else{
        printf("00");
        return 0;
    } if((abs(R3 - X3) == 1) || ((R3 == 6 && X3 == 4) || (R3 == 4 && X3 == 6))){
        printf("1");
        return 0;
    } else{
        printf("0");
        return 0;
    }
}
