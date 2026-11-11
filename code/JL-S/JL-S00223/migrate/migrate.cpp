#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e6 + 10;
ll pre[N], nxt[N], a[N], l[N], r[N];
vector<int> pd[N], nd[N];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int c, t;
    cin >> c >> t;
    while  (t--) {
        ll n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> a[i], l[i] = r[i] = 1, pd[i].clear(), nd[i].clear();
        for (int i = 1, t = 1; i <= n; i++) {
            while (t < i && a[t] < a[i]-d) ++t;
            pre[i] = t;
        }
        for (int i = n, t = n; i >= 1; i--) {
            while (t > i && a[t] > a[i]+d) --t;
            nxt[i] = t;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            pd[pre[i]].push_back(i);
            nd[nxt[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            if (nxt[pre[i]] == i) l[i] = l[pre[i]] + 1;
            for (int x : nd[i]) if (pre[i] < x) ++l[i];
        }
        for (int i = n; i >= 1; i--) {
            if (pre[nxt[i]] == i) r[i] = r[nxt[i]] + 1;
            for (int x : pd[i]) if (nxt[i] > x) ++r[i];
        }
        for (int i = 2; i < n; i++) {
            if (pre[i] == i || nxt[i+1] == i+1) continue;
            ll a = nd[i+1].end()-upper_bound(nd[i+1].begin(), nd[i+1].end(), pre[i])-(nxt[i]==i+1);
            ll b = lower_bound(pd[i].begin(), pd[i].end(), nxt[i+1])-pd[i].begin()-(pre[i+1]==i);
            if (pre[nxt[i+1]] == i && nxt[pre[i]] == i+1) {
                ans += l[pre[i]]*r[nxt[i+1]];
            }
            if (pre[nxt[i+1]] == i) {
                ans += r[nxt[i+1]]*a;
            }
            if (nxt[pre[i]] == i+1) {
                ans += l[pre[i]]*b;
            }
            ans += a*b;
        }
        cout << ans << "\n";
    }
    return 0;
}
