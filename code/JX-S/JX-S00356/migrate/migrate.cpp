#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define per(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb emplace_back
#define mp make_pair
#define fi first
#define se second

constexpr int MAXN = 2e6 + 5;
constexpr int INF = 0x3f3f3f3f3f3f3f3f;

int n, d;
int x[MAXN], nxt[MAXN], prv[MAXN];
int prefix[MAXN], suffix[MAXN];
int sum[MAXN];
bool vis[MAXN];

void work() {
    cin >> n >> d;
    rep (i, 1, n) cin >> x[i];
    x[0] = -INF, x[n + 1] = INF;
    rep (i, 1, n) {
        nxt[i] = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
        prv[i] = lower_bound(x + 1, x + n + 1, x[i] - d) - x;
    }
    if (n <= 300) {
        int ans = 0;
        rep (l, 1, n) rep (r, l + 1, n) {
            rep (j, l, r) vis[j] = 0;
            int i = l;
            bool flag = true;
            int step = 0;
            while (i < r) {
                vis[i] = true;
                step++;
                if (nxt[i] == i) {
                    flag = false;
                    break;
                }
                i = min(r, nxt[i]);
            }
            if (flag) {
                i = r;
                while (i > l) {
                    vis[i] = true;
                    if (prv[i] == i) {
                        flag = false;
                        break;
                    }
                    i = max(l, prv[i]);
                }
            }
            if (flag) {
                int cnt = 0;
                rep (j, l, r) cnt += vis[j];
                // cerr << step << " " << cnt << endl;
                if (cnt == step + 2) {
                    // cerr << "!" << l << " " << r << endl;
                    ans++;
                }
            }
        }
        cout << ans << endl;
        return;
    }
    rep (i, 1, n) {
        int j = prv[i];
        if (nxt[j] != i || j == i) {
            prefix[i] = 0;
            continue;
        }
        prefix[i] = prefix[j];
        int cur = j;
        for (int t = (1 << 21); t; t >>= 1) {
            if (cur + t >= i) continue;
            if (nxt[cur + t] == i) cur += t;
        }
        prefix[i] += (cur - j + 1);
    }
    per (i, n, 1) {
        int j = nxt[i];
        if (prv[j] != i || j == i) {
            suffix[i] = 0;
            continue;
        }
        suffix[i] = suffix[j];
        int cur = j;
        for (int t = (1 << 21); t; t >>= 1) {
            if (cur - t <= i) continue;
            if (prv[cur - t] == i) cur -= t;
        }
        suffix[i] += (j - cur + 1);
    }
    rep (i, 1, n + 1) {
        sum[i] = sum[i - 1] + suffix[i];
    }
    // rep (i, 1, n) cerr << prv[i] << " " << nxt[i] << endl;
    // cerr << "!" << endl;
    // rep (i, 1, n) cerr << prefix[i] << " " << suffix[i] << endl;
    // cerr << endl;
    int ans = 0;
    rep (i, 1, n) {
        int j = nxt[i];
        if (j <= i + 1) continue;
        int l = x[j - 2] + 1 + d, r = x[j - 1] + d;
        int lit = lower_bound(x + 1, x + n + 1, l) - x;
        int rit = upper_bound(x + 1, x + n + 1, r) - x - 1;
        ans += (rit - lit + 1);
        if (lit <= rit) ans += suffix[rit];
        if (prv[j - 1] == i && lit <= rit) ans += prefix[i] * (rit - lit + 1);
        if (lit <= rit && prv[j - 1] == i) ans += suffix[rit] * prefix[i];
        // rep (j, lit, rit) cerr << i << " " << j << " = " << prefix[i] << " " << suffix[j] << endl;
        // cerr << lit << " " << rit << endl;
        // ans += (sum[rit] - sum[lit - 1]) * prefix[i];
    }
    cout << ans << endl;
}

int c, t;

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> t;
    while (t--) work();

    return 0;
}