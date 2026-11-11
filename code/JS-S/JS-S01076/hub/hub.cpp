#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define ii int
using namespace std;
const ii maxn = 5e5 + 5;
inline void rd(ii &x){
    ii res = 0, f = 1; char c = getchar();
    while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)){ res = res * 10 + c - '0'; c = getchar(); }
    x = res * f;
}
ii c, t;
ii n, k;
inline void solve(){
    rd(n);rd(k);
    for(ii i = 1;i < n;++i){
        ii u, v;
        rd(u);rd(v);
    }
    printf("d\n",n / k - 1);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out"."w",stdout);
    rd(c);rd(t);
    while(t--) solve();
    return 0;
}
