#include <bits/stdc++.h>
using namespace std;
int ax, as, bx, bs;
char asc, bsc;
bool f(char a, char b){
    if (a == 'A' || a == 'B' || a == 'C'){
            if (b == 'A' || b == 'B' || b == 'C'){
                return true;
        }
    }
    else {
        if (a == 'D' || a == 'F'){
            if (b == 'D' || b == 'F'){
                return true;
            }
        }
    }
    return false;
}
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%d %d%c %d %d%c", &ax, &as, &asc, &bx, &bs, &bsc);
    if (ax == bx){
        if (as == bs){
            if (f(asc, bsc)){
                if (abs(asc - bsc) <= 1){
                    printf("1111");
                }
                else printf("1110");
            }
            else printf("1100");
        }
        else printf("1000");
    }
    else printf("0000");
    return 0;
}