#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005];
int ans[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		bool v[m + 5] = {0};
		int w[m + 5] = {0};
		for (int kk = 1; kk <= n; kk++) {
			v[kk] = 0;
			w[kk] = 0;
		}
		for (int j = i; j <= n; j++) {
			if (v[a[j]] != 0) {
				for (int k = w[a[j]]; k < j; k++) {
					v[a[k]] = 0;
					w[a[k]] = 0;
				}
			}
			v[a[j]] = 1;
			w[a[j]] = j;
		}
		for (int j = 1; j <= m; j++) {
			if (v[j]) {
				ans[j]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}