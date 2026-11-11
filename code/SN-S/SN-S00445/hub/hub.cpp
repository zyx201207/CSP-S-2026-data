//³Âè÷ÈÊ SN-S 00445
#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll read() {
    ll x = getchar_unlocked(), res = 0, flag = 1;
    for (; x != EOF && (x < '0' || x > '9'); x = getchar_unlocked())
        if (x == '-')
            flag = -1;
    for (; x >= '0' && x <= '9'; x = getchar_unlocked())
        res = res * 10 + x - '0';
    return res * flag;
}

const ll MAXN = 5e5 + 5, MAXLINE = 35;;
ll n, m, a[MAXN];
ll w[MAXN];
struct line{ll k, t[35], a[35];} lines[MAXN];
struct node{ll x, y;} asks[MAXN];
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ll c = read(), n = read(), m = read(), d = read(), q = read();
    for (ll j = 0; j < m; ++j)  w[j] = read();
    for (ll j = 0; j < n; ++j) {
        lines[j].k = read();
        for (ll i = 0; i < lines[j].k; ++i) {
            lines[j].a[i] = read();
            lines[j].t[i] = read();
        }
    }
    for (ll j = 0; j < q; ++j)  asks[j].x = read(), asks[j].y = read();
    cout << rng() << "\n";
}
