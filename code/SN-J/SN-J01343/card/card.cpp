#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5, M = 3e5+5;
int n, m, a[N], ans[M], card[N];
 
int judge(int x, int st) {
	for (int k = st; k <= n; k++) {
		if (card[k] == x) return k;
	}
	return 0;
}

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int t = 1; t <= n; t++) {
		for (int i = t; i <= n; i++) {
			card[i] = 0;
		}
		for (int i = t; i <= n; i++) { 
			if (!judge(a[i], t)) {
				card[i] = a[i];
			}
			else {
				int pos = judge(a[i], t);
				for (int j = pos; j <= n; j++) {
					card[j] = 0;
				}
				card[i] = a[i];
			}
		}
		for (int i = t; i <= n; i++) {
			if (card[i]) ans[card[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0; 
}
