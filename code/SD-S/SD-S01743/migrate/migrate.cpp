#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

using ll = long long;

ll read() {
	ll res = 0, si = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') si = -si; ch = getchar(); }
	while (ch >= '0' && ch <= '9') res = 10 * res + ch - '0', ch = getchar();
	return res * si;
}

ll n, d, x[N];
ll pre[N], suf[N], p[N];
bool tag[N]; // inner tag 
int q[N], h, t;
bool check(int pos) {
	return  (x[pos + 1] - x[pos] <= d) && \
			(x[pos + 2] - x[pos + 1] <= d) && \
			(x[pos + 3] - x[pos + 2] <= d) && \
			(x[pos + 2] - x[pos] <= d) && \
			(x[pos + 3] - x[pos + 1] <= d) && \
			(x[pos + 3] - x[pos] > d);
}
void solve() {
	n = read(), d = read();
	for (int i = 1; i <= n; i++) x[i] = read();
	for (int i = 0; i <= n + 1; i++) pre[i] = p[i] = tag[i] = 0;
	h = 1, t = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		while (h <= t && x[i] - x[q[h]] > d) h++, cnt++;
		tag[i] = 1, pre[i] = p[i] = 1;
		if (h <= t && q[h] == i - 1) {
			pre[i - 1] = p[i - 1] = cnt;
			pre[i] = pre[i - 1] + p[i - 1], p[i] = p[i - 1];
		}
		q[++t] = i;
	}
	h = 1, t = 0;
	for (int i = 0; i <= n + 1; i++) p[i] = suf[i] = tag[i] = 0;
	for (int i = n; i; i--) {
		int cnt = 0;
		while (h <= t && -x[i] + x[q[h]] > d) h++, cnt++;
		tag[i] = 1, suf[i] = p[i] = 1;
		if (h <= t && q[h] == i + 1) {
			suf[i + 1] = p[i + 1] = cnt;
			suf[i] = suf[i + 1] + p[i + 1], p[i] = p[i + 1];
		}
		q[++t] = i;
	}
	for (int i = 1; i <= n; i++) cerr << pre[i] << ' ' << suf[i] << '\n';
	cerr << '\n';
	ll ans = 0;
	for (int i = 1; i <= n - 3; i++) {
		if (check(i)) {
			cerr << i << ' ' << ((i == 1 || x[i + 1] - x[i - 1] > d) ? pre[i] : 1) << ' '\
			<< ((i + 3 == n || x[i + 4] - x[i + 2] > d) ? suf[i + 3] : 1) << '\n';
			ans += ((i == 1 || x[i + 1] - x[i - 1] > d) ? pre[i] : 1) * \
					((i + 3 == n || x[i + 4] - x[i + 2] > d) ? suf[i + 3] : 1);
		}
	}
	cerr << '\n';
	printf("%lld\n", ans);
}

int main() {
	freopen("migrate2.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	freopen("dbg.txt", "w", stderr);
	ll c = read(), t = read();
	while (t--) {
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 1
12 5
1 2 3 5 8 11 16 21 26 30 31 32
*/
