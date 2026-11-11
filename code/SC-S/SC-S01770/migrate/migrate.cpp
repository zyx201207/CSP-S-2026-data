#include <iostream>
using namespace std;
typedef long long ll;

inline ll read() {
	ll w = 0, f = 1, ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') w = w * 10 + ch - '0', ch = getchar();
	return f * w;
}

inline void write(ll x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x < 10) {
		putchar(x + '0');
		return ;
	}
	write(x / 10);
	putchar(x % 10 + '0');
	return ;
}

const int N = 2e6 + 5;

ll a[N];
ll nxt[N];

void solve() {
	ll n = read(), d = read(), ans = 0;
	for (int i = 1; i <= n; ++i) a[i] = read(), nxt[i] = i - 1;
	for (int i = 4; i <= n; ++i) {
		ll last = i;
		bool flag = 0;
		for (int j = i - 1;j >= 1; --j) {
			if (a[last] - a[j] > d) {
				if (last == j + 1) {
					flag = 1;
					break;
				}
				last = j + 1;
			}
			nxt[j] = last;
		}
		if (!flag) last = 1;
		for (int j = 1; j <= i - 3; ++j) {
			if (last > j) continue;
			ll res = 1;
			if (a[nxt[j] + 1] - a[j] <= d && nxt[nxt[j]] == nxt[nxt[j] + 1]) ++res;
			if (a[nxt[j] + 2] - a[j] <= d && nxt[nxt[j]] == nxt[nxt[j] + 2]) ++res;
			if (res == 2) ++ans;
		}
		//for (int j = 1;j <= i - 1; ++j) cout << nxt[j] << ' ';
		//cout << '\n';
	}
	write(ans);
	putchar('\n');
}

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c = read(), t = read();
	while (t--) solve();
	return 0;
}