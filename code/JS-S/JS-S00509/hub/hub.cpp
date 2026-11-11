#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
void read(ll& res) {
    res = 0;
    int ch = getchar_unlocked();
    bool neg = 0;
    while (ch != EOF && ch != '-' && (ch < '0' || ch > '9')) ch = getchar_unlocked();
    if (ch == EOF) return;
    if (ch == '-') neg = 1, ch = getchar_unlocked();
    while ('0' <= ch && ch <= '9') res = res * 10 + ch - 48, ch = getchar_unlocked();
    if (ch != EOF) ungetc(ch, stdin);
    if (neg) res = -res;
}
const int N = 1e6 + 7;
vector<ll> g[N];
ll n, m, ans = LLONG_MAX;
bool added[N], vis[N];
ll calc(ll i) {
    queue<pll> que;
    que.emplace(i, 0);
    for (ll x = 1; x <= n; ++x) vis[x] = 0;
    vis[i] = 1;
    while (que.size()) {
        ll u = que.front().first, step = que.front().second;
        que.pop();
        for (ll v : g[u]) {
            if (vis[v]) continue;
            if (added[v]) return step + 1;
            vis[v] = 1, que.emplace(v, step + 1);
        }
    }
}
set<ll> nxt;
void dfs(ll l) {
    if (!l) {
        ll res = 0;
        for (ll i = 1; i <= n; ++i)
            if (!added[i])
                res = max(res, calc(i));
        ans = min(ans, res);
        return;
    }
    for (ll v : nxt) {
        if (added[v]) continue;
        added[v] = 1;
        set<ll> tmp(nxt);
        for (ll i : g[v]) tmp.insert(i);
        nxt.swap(tmp);
        dfs(l - 1);
        tmp.swap(nxt);
        added[v] = 0;
    }
}
void solve() {
    read(n), read(m);
    ans = n;
    for (ll i = 1, u, v; i < n; ++i) {
        read(u), read(v);
        g[u].push_back(v), g[v].push_back(u);
    }
    if (m == n) {
        cout << "0\n";
        return;
    }
    for (ll i = 1; i < n; ++i) {
        for (ll j = i + 1; j <= n; ++j) {
            nxt.insert(i), nxt.insert(j);
            for (ll v : g[i]) {
                nxt.insert(v);
            }
            for (ll v : g[j]) {
                nxt.insert(v);
            }
            added[i] = added[j] = 1;
            dfs(m - 2);
            nxt.clear();
            added[i] = added[j] = 0;
        }
    }
    cout << ans << '\n';
    for (ll i = 1; i <= n; ++i) g[i].clear();
}
namespace SubA {
    void solve() {
        ll n, k;
        read(n), read(k);
        for (ll i = 1, u, v; i < n; ++i) read(u), read(v);
        if (k == n) {
            cout << "0\n";
            return;
        }
        if (k >= n / 2) { cout << "1\n"; return; }
        ll m = n / 2;
        cout << (m / (k + 1) + 1) << '\n';
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ll c, T;
    read(c), read(T);
    if (13 <= c && c <= 14) { while (T--) SubA::solve(); return 0; }
    while (T--) solve();
    // solve();
    return 0;
}
