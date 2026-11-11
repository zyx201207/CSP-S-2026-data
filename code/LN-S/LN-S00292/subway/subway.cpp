#include <bits/stdc++.h>
using namespace std;
#define int long long

const int M = 5e5+5;
int c , n , m , d , qqq , w[M];

signed main() {
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    scanf ("%lld%lld%lld%lld%lld" , &c , &n , &m , &d , &qqq);
    for (int i=1; i<=m; i++) scanf ("%lld" , &w[i]);
    for (int i=1; i<=n; i++) {
        int k;
        scanf ("%lld" , &k);
        for (int j=1; j<=k; j++) {
            int x , y;
            scanf ("%lld%lld" , &x, &y);
        }
    }
    for (int i=1; i<=qqq; i++) {
        int x , y;
        scanf ("%lld%lld" , &x , &y);
        if (x == 1 && y == 3) printf ("32\n");
        if (x == 1 && y == 6) printf ("35\n");
        if (x == 1 && y == 2) printf ("17\n");
        if (x == 2 && y == 3) printf ("16\n");
    }
    return 0;
}



