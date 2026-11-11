#include <bits/stdc++.h>
// I AK IOI !!!!!!!!
using namespace std;

typedef long long ll;
typedef long double ld;

ll cas, T;
ll n, d, a[2000010];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> cas >> T;
    while (T--) {
        scanf("%Ld%Ld", &n, &d);
        for (int i = 1; i <= n; i++) {
            scanf("%Ld", &a[i]);
        }
        bool _A = 1;
        for (int i = 3; i <= n; i++) {
            if (a[i] - a[i - 1] != a[2] - a[1]) _A=0;
        }
        if (_A) {
            if (d <= a[2] - a[1]) {
                cout << "0\n";
                continue;
            }
            else {
                cout << max(n - (d / (a[2] - a[1])) * 2 + 1, 0ll) << "\n";
                continue;
            }
        }
        vector<ll> f(n + 3), g(n + 3), cnt1(n + 3), cnt2(n + 3), p1(n + 3), p2(n + 3);
        // zui yuan dian
        ll l = 1, r = n;
        for (int i = 1; i <= n; i++) {
            while (a[i] - a[l] > d) l++;
            f[i] = l;
            if (l != i)cnt2[l]++;
        }
        for (int i = n; i >= 1; i--) {
            while (a[r] - a[i] > d) r--;
            g[i] = r;
            if (r != i)cnt1[r]++;
        }
        // shuang xiang lian
        vector<bool> vis(n + 3);
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                vector<ll> s;
                s.push_back(i);
                ll x = i;
                while (g[x] != x && f[g[x]] == x) {
                    x = g[x];
                    s.push_back(x);
                    vis[x] = 1;
                }
                ll len = s.size();
                p1[i] = cnt1[i];
                for (int j = 1; j < len; j++) {
                    p1[s[j]] = p1[s[j - 1]] + cnt1[s[j]];
                }
                p2[s[len - 1]] = cnt2[s[len - 1]];
                for (int j = len - 2; j >= 0; j--) {
                    p2[s[j]] = p2[s[j + 1]] + cnt2[s[j]];
                }
            }
        }
        // calc
        ll ans = 0;
        for (int i = 1; i < n; i++) {
            if (a[i + 1] - a[i] <= d) {
                if (f[i + 1] == i && g[i] == i + 1)continue;
                ans += (p1[i + 1] - bool(g[i] == i + 1)) * (p2[i] - bool(f[i + 1] == i));
                //cout << (p1[i + 1] - bool(g[i] == i + 1)) * (p2[i] - bool(f[i + 1] == i)) << " ";
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
