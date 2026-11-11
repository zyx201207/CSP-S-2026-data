#include <bits/stdc++.h>

using namespace std;

#define int long long
#define up(i, a, b) for(int i = a;i <= b; i++)

const int N = 2e5 + 101;
int a[N], n, s;

inline bool comp(int a, int b) {
    return a > b;
}

bool ok;

inline void solve(){
    cin >> n >> s;
    up (i, 1, n) {
        cin >> a[i];
        int q = a[i], c = 2;
        while (q) {
            if (q == c) {
                a[i] = 0;
                break;
            }
            q >>= 1;
        }
    }
    sort(a + 1, a + 1 + n, comp);
    cout << a[s] << '\n';
}
signed main () {
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
    return 0;
    // CSP AK!!!
}
