#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+10 , M = 3e5+10;
int n , a[N] , m , s[M] , ans[M];

signed main() {
    freopen ("card.in" , "r" , stdin);
    freopen ("card.out" , "w" , stdout);
    scanf ("%lld%lld" , &n , &m);
    for (int i=1; i<=n; i++) scanf ("%lld" , &a[i]);
    if (m > 1) {
        for (int i=1; i<=n; i++) {
        int c[N] , k = 0;
        for (int j=1; j<=m; j++) s[j] = 0;
        for (int j=i; j<=n; j++) {
            if (s[a[j]] != 0) {
                for (int l=s[a[j]]+1; l<=k; l++) {
                    s[a[l]] = 0;
                }
                k = s[a[j]];
                c[k] = a[j];
            }
            else {
                s[a[j]] = j;
                c[++k] = a[j];
            }
        }
        for (int j=1; j<=k; j++) ans[c[j]]++;
        }
        for (int i=1; i<=m; i++) printf ("%lld " , ans[i]);
    }
    else {
        printf ("%lld" , n);
    }
    return 0;
}


