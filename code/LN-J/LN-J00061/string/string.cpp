#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+10;
int n , a[N] , m , ans;
char c[N] , s[150000000];

signed main() {
    freopen ("string.in" , "r" , stdin);
    freopen ("string.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i] >> c[i];
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=a[i]; j++) {
            s[++m] = c[i];
        }
    }
    for (int i=1; i<=m/2; i++) {
        if (s[i] != s[m+1-i]) ans++;
    }
    printf ("%lld" ,ans);
    return 0;
}

