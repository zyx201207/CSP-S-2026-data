#include <bits/stdc++.h>
// I Want 100pts !!!!!!!
using namespace std;

typedef long long ll;
typedef long double ld;

ll cas, T;
ll n, k;
vector<vector<ll>> t;

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> cas >> T;
    ll N = 0;
    while (T--) {
        cin >> n >> k;
        N += n;
        t = vector<vector<ll>>(n + 3);
        for (int i = 1; i < n; i++) {
            ll u, v;
            cin >> u >> v;
            t[u].push_back(v);
            t[v].push_back(u);
        }
        if (n <= 10 && N <= 30) {
            ll ans = 1e18;
            for (ll m = 0; m < (1 << n); m++) {
                ll sum = 0;
                queue<ll> Q;
                vector<ll> d(n + 1, 1e18), f(n + 1, 0);
                for (int i = 0; i < n; i++) if ((m >> i) & 1) {
                    sum++; Q.push(i + 1), d[i + 1] = 0;
                }
                if (sum == k) {
                    ll g = 0;
                    for (int i = 0; i < n; i++) if ((m >> i) & 1) {
                        if (!f[i + 1]) {
                            f[i + 1] = 1;
                            g++;
                            queue<ll> Q;
                            Q.push(i + 1);
                            while (!Q.empty()) {
                                ll x = Q.front(); Q.pop();
                                for (auto v : t[x]) {
                                    if (d[v] == 0 && !f[v]) {
                                        f[v] = 1;
                                        Q.push(v);
                                    }
                                }
                            }
                        }
                    }
                    if (g > 2) continue;
                    ll mx = 0;
                    while (!Q.empty()) {
                        ll now = Q.front();Q.pop();
                        for (auto i : t[now]) {
                            if (d[i] > d[now] + 1) {
                                d[i] = d[now] + 1;
                                Q.push(i);
                                mx = max(mx, d[i]);
                            }
                        }
                    }
                    //cout << m << " " << mx << "\n";
                    ans = min(ans, mx);
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
