#include <bits/stdc++.h>
using namespace std;
#define int long long
int ds[300005];
int p[500005];
bool p2[500005], ds2[300005];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int q = 1; q <= n; q++) {
		for (int i = 1; i <= m; i++)
			ds2[i] = false;
		for (int i = 0; i < n; i++)
			p2[i] = true;
		for (int i = q; i <= n; i++) {
			if (ds2[p[i]]) {
				for (int j = i - 1; j >= 0; j--) {
					if (p2[j] && p[j] == p[i]) {
						p2[j] = false;
						break;
					}
					ds2[p[j]] = false;
					p2[j] = false;
				}
			}
			ds2[p[i]] = true;
		}
		for (int i = 1; i <= m; i++) {
			if (ds2[i])
				ds[i]++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ds[i] << " ";
	return 0;
}