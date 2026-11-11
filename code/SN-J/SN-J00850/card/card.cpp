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
const ll MAXN = 5e5 + 5;
bool flag[MAXN];
ll cnt[MAXN], a[MAXN];
int main() {
    freopen("card1.in", "r", stdin);
    freopen("card1.out", "w", stdout);
    ll n = read(), m = read();
    for (ll j = 1; j <= n; ++j)   a[j] = read();
    queue<ll> q;
    for (ll j = 1; j <= m; ++j) {
        for (long long i = j; i <= n; ++i) {
            if (!flag[i]) {
                q.push(i);
                flag[i] = true;
            }
            else {
                ll x = q.front(); q.pop(); flag[x] = false;
                while (x != i) {
                    x = q.front(); q.pop(); flag[x] = false;
                }
            }
        }
        while (!q.empty()) {
            ll x = q.front(); q.pop(); flag[x] = false;
            cnt[x]++;
        }
    }
    for (ll j = 1; j <= m; ++j) cout << cnt[j] << " ";
    return 0;
}
