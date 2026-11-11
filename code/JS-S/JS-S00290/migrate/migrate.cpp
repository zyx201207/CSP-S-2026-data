#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e6 + 9;
const ll INF = 1e18;
ll x[N];
int lpos[N];
int c, n;
ll d;

namespace sub1{
    ll f[N], g[N], sum[309][309];
    ll ans;

    bool check(int l, int r){
        for(int i = l; i <= r; i++){
            f[i] = INF;
            g[i] = 0;
        }
        f[l] = 0;
        g[l] = 1;
        for(int i = l + 1; i <= r; i++){
            ll mn = INF;
            for(int j = i - 1; j >= l; j--){
                if(x[i] - x[j] > d) break;
                mn = min(mn, f[j]);
            }
            f[i] = mn + 1;
            for(int j = i - 1; j >= l; j--){
                if(x[i] - x[j] > d) break;
                if(mn == f[j]) g[i] += g[j];
            }
        }

        return g[r] == 2;
    }

    void solve(){
        ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if(check(i, j)) cout << i << ' ' << j << '\n';
                ans += check(i, j);
            }
        }
        cout << ans << '\n';
    }
}

void solve(){
    cin >> n >> d;
    if(n == 1){
        cout << 0 << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) cin >> x[i];
    int L = 1;
    for(int i = 1; i <= n; i++){
        while(L + 1 <= i && x[i] - x[L] > d) L++;
        lpos[i] = L;
    }
    if(c <= 6){
        sub1::solve();
        return;
    }
    if(c == 11 || c == 12){
        ll len = (d + x[2] - x[1] - 1) / (x[2] - x[1]);
        cout << d << ' ' << x[2] - x[1] << '\n';
        len = min(len, 1ll * n);
        if(len <= 1) {
            cout << 0 << '\n';
            return;
        }
        len++;
        if(len & 1) cout << max(0ll, n - len) << '\n';
        else cout << max(0ll, n - len - 1) << '\n';
        return;
    }
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int T;
    cin >> c >> T;
    while(T--) solve();   
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2 
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 3
10 14
-31 -24 -17 -10 -3 4 11 18 25 32
10 21
0 7 14 21 28 35 42 49 56 63
10 22
0 7 14 21 28 35 42 49 56 63
*/