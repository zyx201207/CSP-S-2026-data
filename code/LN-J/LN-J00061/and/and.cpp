#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+10;
int n , a[N] , m , ans , maxn , x;
bool t = true;

signed main() {
    freopen ("and.in" , "r" , stdin);
    freopen ("and.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (t && a[i] == i) {
            t = true;
        }
        else {
            t = false;
        }
        maxn = max(maxn , a[i]);
    }
    if (m == 1) {
        printf ("%lld" , maxn);
        return 0;
    }
    if (m == n) {
        x = a[1];
        for (int i=2; i<=n; i++) x = x&a[i];
        printf ("%lld" , x);
        return 0;
    }
    int s = 0 , c = 0;
    for (int i=0; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            if ((i >> j) & 1) {
                if (c == 0) {
                    s = a[j];
                    c++;
                    if (c == m) break;
                }
                else {
                    s = s&a[j];
                    c++;
                    if (c == m) break;
                }
            }
        }
        if (c == m) ans = max(ans , s);
        s = c = 0;
    }
    printf ("%lld" , ans);
    return 0;
}

