#include<bits/stdc++.h>
#define ld long double
#define ll long long
#define ii int
#define lowbit(x) ((x) & (-(x)))
#define ls ((root) << 1)
#define rs ((root) << 1 | 1)
#define mid (((l) + (r)) >> 1)
#define fi first
#define se second
using namespace std;
ld Maybe_1_0_ = 0.000000000001;
const ii maxn = 5e5 + 5;
inline void rd(ii &x){
    ii res = 0, f = 1; char c = getchar();
    while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)){ res = res * 10 + c - '0'; c = getchar(); }
    x = res * f;
}
inline void rdll(ll &x){
    ll res = 0, f = 1; char c = getchar();
    while(!isdigit(c)){ if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)){ res = res * 10 + c - '0'; c = getchar(); }
    x = res * f;
}
ii n, ans = 1, l;
ll m, a[maxn];
__int128 cost;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    rd(n);rdll(m);
    l = 1;
    cost = 0;
    for(ii i = 1;i <= n;++i) rdll(a[i]);
    sort(a + 1,a + n + 1,[](const ll &A, const ll &B){
         return A < B;
    });
    /*
    for(ii i = 1;i <= n;++i){
        ii l = i;
        ll cost = m;
        for(ii j = i - 1;j >= 1;--j){
            if(cost >= (a[i] - a[j])) l--, cost -= (a[i] - a[j]);
        }
        ans = max(ans,(i - l + 1));
    }
    */
    for(ii r = 1;r <= n;++r){
        cost = cost + (a[r] - a[r - 1]) * (r - l);
        while(cost > m){
            cost -= a[l];
            ++l;
        }
        ans = max(ans,r - l + 1);
    }
    printf("%d\n",ans);
    return 0;
}
