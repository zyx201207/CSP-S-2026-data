#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[300005], b[300005], ans[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int cs = 1; cs <= n; cs++) {
		int p = cs - 1;
		int e[300005] = {};
		for (int i = cs; i <= n; i++) {
			p++;
			b[p] = a[i];
			if (e[b[p]] == 0) {
				e[b[p]] = p;
			} else {
				for (int i = e[b[p]]; i <= p; i++) {
					if (e[b[i]] > e[b[p]]) {
						e[b[i]] = 0;
					}
				}
				p = e[b[p]];
				if (b[p] == b[p - 1]) {
					p--;
					e[b[p]] = p;
				}
			}
		}
		for (int i = cs; i <= p; i++) {
			ans[b[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
