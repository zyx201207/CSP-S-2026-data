#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct Node {
	ll s, e, id;
} g[200005];
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, cnt = 0;
	bool f = 1;
	char pre = 'A';
	ll su = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		char x;
		cin >> a >> x;
		if (x == pre) {
			g[cnt].e += a;
		} else {
			g[++cnt].s = su + 1;
			g[cnt].e = su + a;
			g[cnt].id = x - 'a';
		}
		pre = x;
		su += a;
	}
	if (cnt == 1) {
		cout << 0;
		return 0;
	}
	if (su % 2) f = 0;
	ll m = (su >> 1) + 1, ans = 0;
	int l = 1, r = cnt;
	while (l <= r) {
		if (g[l].e >= m) {
			ans += min(g[l].e - m + f, m - g[l].s);
			break;
		}
		if (g[r].id != g[l].id) {
			if (2 * m - g[r].s - f < g[l].e) {
				r--;
			} else if (2 * m - g[r].s - f > g[l].e) {
				l++;
			} else {
				r--;
				l++;
			}
			continue;
		}
//		if (g[l].e < 2 * m - g[r].s - f) {
// 			l++;
//			continue;
//		}
//		if (g[l].s > 2 * m - g[r].e - f) {
//			r--;
//			continue;
//		}
		ans += min(2 * m - g[r].s - f, g[l].e) - max(2 * m - g[r].e - f, g[l].s) + 1;
		if (2 * m - g[r].s - f < g[l].e) {
			r--;
		} else if (2 * m - g[r].s - f > g[l].e) {
			l++;
		} else {
			r--;
			l++;
		}
	}
	cout << m - 1 - ans;
	return 0;
}