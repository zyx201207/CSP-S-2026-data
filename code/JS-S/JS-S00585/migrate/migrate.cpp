#include <bits/stdc++.h>
#define int long long
#define rg register
using namespace std;
const int MAXN = 2000005;
inline void fre(){
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    return ;
}
int c, t, n, d;
int x[MAXN];
signed main()
{
    fre();
    scanf ("%lld%lld", &c, &t);
    while (t--){
        scanf ("%lld%lld", &n, &d);
        for (rg int i = 1; i <= n; i++){
            scanf ("%lld", &x[i]);
        }
        if (n % 2 == 0) printf ("%lld", n/2-1);
        else printf ("%lld\n", n/2);
    }
    return 0;
}
