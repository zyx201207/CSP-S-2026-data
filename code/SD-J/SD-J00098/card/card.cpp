#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], ans[500005];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int t = 1; t <= n; t++) {
		vector<bool> b(300005, 0);
		vector<int> v(500005, 0);
		int sz = 0;
		for (int i = t; i <= n; i++) {
			if (!b[a[i]]) {
				b[a[i]] = 1;
				v[++sz] = a[i];
			} else {
				while (v[sz] != a[i] && sz) {
					b[v[sz]] = 0;
					sz--;
				}
			//	v[++sz] = a[i];
				b[a[i]] = 1;
			}
		}
		for (int i = 1; i <= sz; i++) {
			ans[v[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
