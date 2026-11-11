#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, a[N], ans;
char c[N];
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%lld", &n);
    for(int i = 1; i <= n; i ++){
        scanf("%lld %c", &a[i], &c[i]);
    }
    int li = 1, ri = n;
    int lx = a[1], rx = a[n];
    while(li < ri){
        if(lx < rx){
            if(c[li] != c[ri]){
                ans += lx;
            }
            rx -= lx;
            li ++;
            lx = a[li];
        }
        else if(lx > rx){
            if(c[li] != c[ri]){
                ans += rx;
            }
            lx -= rx;
            ri --;
            rx = a[ri];
        }
        else{
            if(c[li] != c[ri]){
                ans += lx;
            }
            li ++, ri --;
            lx = a[li], rx = a[ri];
        }
    }
    printf("%lld\n", ans);
    return 0;
}