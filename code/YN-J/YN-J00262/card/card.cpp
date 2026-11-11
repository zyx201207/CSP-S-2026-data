//T4
#include <bits/stdc++.h>
using namespace std;
long long n, m, pp, a[2000005], c[2000005], ans[2000005];
bool vis[2000005];
int cntt[5000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	if (m >= 100000) {
		int fl = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			c[a[i]] = i;
			if (a[i] < a[i - 1]) {
				fl = 1;
			}
		}
		if (fl == 0) {
			for (int i = 1; i <= n; i++) {
				cntt[a[i]]++;
				ans[a[i]] = i;
			}
			for (int i = 1; i <= m; i++) {
				cout << ans[i] << " ";
			}
		} else {
			pp = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == a[i + 1]) {
					pp++;
					continue;
				}
				for (int j = 1; j <= m; j++) {
					vis[j] = 0;
				}
				for (int j = i; j <= n; j++) {
					j = c[a[j]];
					if (!vis[a[j]]) {
						vis[a[j]] = 1;
						ans[a[j]]++;
						ans[a[j]] += pp;
					}
				}
				pp = 0;
			}
			for (int i = 1; i <= m; i++) {
				cout << ans[i] << " ";
			}
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		c[a[i]] = i;
	}
	pp = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i + 1]) {
			pp++;
			continue;
		}
		for (int j = 1; j <= m; j++) {
			vis[j] = 0;
		}
		for (int j = i; j <= n; j++) {
			j = c[a[j]];
			if (!vis[a[j]]) {
				vis[a[j]] = 1;
				ans[a[j]]++;
				ans[a[j]] += pp;
			}
		}
		pp = 0;
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}