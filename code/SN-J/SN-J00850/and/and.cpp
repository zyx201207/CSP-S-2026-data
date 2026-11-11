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
const ll MAXN = 2e5 + 5;
ll a[MAXN], n, m;
bool two[MAXN][35];
bool flag[MAXN];//是否在候选 
void init() {
	for (ll j = 0; j < n; ++j) {
		ll t = a[j], cnt = 0;
		while (t) {
			two[j][cnt++] = t % 2, t /= 2;
		}
	}
}
ll solve() {
	init();
    ll res = 0;
    for (ll j = 0; j <= n; ++j)	flag[j] = true; 
	for (ll j = 33; j >= 0; --j) {
        ll cnt = 0;
        for (ll i = 0; i < n; ++i) {
            if (flag[i]) {
                if (two[i][j]) {
                    cnt++;
                }
            }
        }
        if (cnt >= m) {
            for (long long i = 0; i < n; ++i) {
                if (flag[i]) {
                    if (!two[i][j]) {
                        flag[i] = false;
                    }
                }
            }
            res += (1 << j);
        }
	}
    return res;
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	n = read(), m = read();
	for (ll j = 0; j < n; ++j)	a[j] = read();
    return cout << solve(), 0;
}