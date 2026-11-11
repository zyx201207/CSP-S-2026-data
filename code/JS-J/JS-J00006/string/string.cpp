#include<bits/stdc++.h>
using namespace std;

int n, a, b;
char c, d;

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    if(n == 1){
        scanf("%d%c", &a, &c);
        printf("0");
    } else{
        scanf("%d%c%d%c", &a, &c, &b, &d);
        if(c == d){
            printf("0");
        } else{
            printf("%d", min(a, b));
        }
    }
    return 0;
}
