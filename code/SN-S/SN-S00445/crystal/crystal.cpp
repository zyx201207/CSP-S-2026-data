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

const ll MAXN = 5e5 + 5;
ll n, m, a[MAXN];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ll n = read(), m = read();
    for (ll j = 1; j <= n; ++j) {
        a[j] = read();
    }
    sort(a + 1, a + n + 1);

    ll ans = 0;
    __int128 use = 0, cur_cnt = 0, last_have = 0;
    for (ll j = 1; j <= n; ++j) {
        while (j != 1 && use + cur_cnt * (a[j] - a[j - 1]) > m) {
            use -= a[j - 1] - a[last_have];
            last_have++;
            cur_cnt--;
        }
        use += cur_cnt * (a[j] - a[j - 1]);
        cur_cnt++;
        ans = max(ans, (ll)cur_cnt);
    }
    return cout << ans << "\n", 0;
}
