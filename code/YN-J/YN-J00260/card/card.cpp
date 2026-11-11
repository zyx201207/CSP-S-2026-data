#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
long long n, m, a[N], q[N], fi[N], h[N], vis[M], t, w, ans[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 5000) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				h[j] = j + 1;
				fi[a[j]] = 0;
			}
			for (int j = 1; j <= n; j++) {
				q[j] = j - 1;
			}
			for (int j = i; j <= n; j++) {
				if (!fi[a[j]]) {
					fi[a[j]] = j;
				} else {
					h[q[fi[a[j]]]] = j;
					q[j] = q[fi[a[j]]];
					fi[a[j]] = j;
				}
			}
			for (int j = q[i]; j <= n; j = h[j]) {
				if (j != 0 && !vis[a[j]] && j >= i) {
					ans[a[j]]++;
					vis[a[j]] = 1;
				}
			}
			for (int j = 1; j <= m; j++)
				vis[j] = 0;
		}
		for (int i = 1; i <= m; i++) {
			cout << ans[i] << " ";
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (!fi[a[i]]) {
				fi[a[i]] = 1;
				ans[a[i]] = i;
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << ans[i] << " ";
		}
	}
	return 0;
}
