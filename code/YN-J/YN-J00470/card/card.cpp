#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int a[3000005], vis[3000005], viz[3000005], ll[3000005];

int main() {
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(ll, 0, sizeof ll);
	for (int i = 1; i <= n; i++) {
		memset(vis, -1, sizeof vis);
		memset(viz, -1, sizeof viz);
		for (int j = i; j <= n; j++) {
			if (vis[a[j]] > 0) {
				for (int k = viz[j - i]; k >= 1; k--) {
					vis[viz[k]] = -1;
					viz[k] = -1;
					if (viz[k] == a[j])
						break;
				}
			}
			vis[a[j]] = 1;
			viz[j - i + 1] = a[j];
		}
		for (auto p : viz) {
			ll[p]++;
		}
	}
	for (auto i : ll) {
		if (i > 0)
			cout << i << ' ';
	}
	return 0;
}