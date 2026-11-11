#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3 + 7;
int n, m;
int a[N];
map<int, bool> ma[N];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int b[N] = {0}, cnt = 0, tt[N] = {0}, cnt1 = 0;
		map<int, bool> t;
		t.clear();
		for (int j = i; j <= n; j++) b[++cnt] = a[j];
		for (int j = 1; j <= n; j++) {
			if (t[b[j]] == 0) tt[++cnt1] = b[j], t[b[j]] = 1;
			else {
				int id = 0;
				for (int k = 1; k <= cnt1; k++) {
					if (tt[k] == b[j]) {
						id = k;
						break;
					}
				}
				for (int k = id + 1; k <= cnt1; k++) t[b[j]] = 0;
				cnt1 = id;
			}
		}
		for (int j = 1; j <= cnt1; j++) ma[i][tt[j]] = 1;
	}
	for (int i = 1; i <= m; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			if (ma[j][i] == 1) ans++;
		}
		cout << ans << " ";
	}
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
signed main() {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int T = 1;
//	cin >> T;
	while (T--) solve();
	return 0;
}

