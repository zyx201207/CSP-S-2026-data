#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5005;
int n, d, x[N], L[N], R[N];
bitset<N> f1[N], f2[N];
inline void solve() {
    cin >> n >> d;
    for(int i = 1; i <= n; i++) cin >> x[i], f1[i].reset(), f2[i].reset();
    for(int i = 1; i <= n; i++) {
        L[i] = R[i] = i;
        for(int j = i; j <= n; j++) {
            if(x[j] - x[i] <= d) R[i] = j;
            else break;
        }
        for(int j = i; j; j--) {
            if(x[i] - x[j] <= d) L[i] = j;
            else break;
        }
        cerr << L[i] << ' ' << R[i] << endl;
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j = R[j]) {
            f1[i][j] = 1;
            if(j == R[j]) break;
        }
        for(int j = i; j; j = L[j]) {
            f2[i][j] = 1;
            if(j == L[j]) break;
        }
    }
    bitset<N> p;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            // p = f1[i] & f2[j];
            int cnt = 0;
            for(int k = i; k <= j; k++) {
                if(!f1[i][j] && !f2[i][j]) continue;
                if(f1[i][j] && f2[i][j]) continue;
                cnt++;
            }
            if(cnt == 2) res++;
        }
    }
    cout << res << '\n';
}
signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    // freopen("err.out", "w", stderr);
    cin.tie(0) -> sync_with_stdio(0);
    int c, t;
    cin >> c >> t;
    while(t--) solve();
}
/*
乐扣保佑！！！！！！
*/