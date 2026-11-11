#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500010], b[500010], cnt, ans[300010], maxx;

struct q {
	long long y, id;
} c[300010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (a[j] != 0) {
				if (c[a[j]].y == 0) {
					cnt++;
					c[a[j]].y = 1;
					c[a[j]].id = cnt;
					b[cnt] = a[j];
					a[cnt] = 0;
				} else {
					for (int z = c[a[j]].id; z <= n; z++) {
						b[z] = 0;
						c[z].y = 0;
						cnt--;
					}
					cnt++;
					b[cnt] = a[j];
					c[a[j]].id = cnt;
				}
			}

		}
		for (int j = 1; j <= cnt; j++) {
			if (ans[b[j]] == 0) {
				ans[b[j]]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}