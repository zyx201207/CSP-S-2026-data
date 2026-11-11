#include <bits/stdc++.h>
using namespace std;
int n, m, ed;
int a[500005], s[500005], sw[300005], ans[300005];
int main( void ) {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int t = 1; t <= n; t++) {
		memset(s, 0, sizeof(s));
		memset(sw, 0, sizeof(sw));
		ed = 1;
		for (int i = t; i <= n; i++) {
			if (sw[a[i]]) {
				ed = sw[a[i]];
				for (int j = ed; j <= n; j++) {
					sw[s[j]] = 0;
					s[j] = 0;
				}
				s[ed] = a[i];
				sw[s[ed]] = ed;
				ed++;
			} else {
				ed++;
				s[ed - 1] = a[i];
				sw[s[ed - 1]] = ed - 1;
			}
		}
		for (int i = 1; i <= m; i++) {
			if (sw[i]) {
				ans[i]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
