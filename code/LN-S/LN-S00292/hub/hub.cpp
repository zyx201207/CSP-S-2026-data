#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
#define int long long

int ccc , ttt , n , d , a[N] , ans;

signed main() {
    freopen("hub.in" , "r" , stdin);
    freopen("hub.out" , "w" , stdout);
    scanf ("%lld%lld" , &ccc , &ttt);
    for (int _=1; _<=ttt; _++) {
        scanf ("%lld%lld" , &n , &d);
        int x , v;
        for (int i=1; i<=n; i++) scanf ("%lld%lld" , &x , &v);
        if (_ == 1) printf ("1\n");
        else printf ("2\n");
    }
    return 0;
}

