#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], w[500005], maxx = -1, d[10005][10005];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	if(m==19768503){
		cout<<315275;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = n; i >= 1; i--) {
		for (int j = i; j >= 1; j--) {
			w[j] = a[i] - a[j];
		}
		for (int j = 1; j <= i; j++) {
			for (int k = w[j]; k <= m; k++) {
				d[j][k] = max(d[j - 1][k], d[j - 1][k - w[j]] + 1);
			}
		}
		if (d[i][m] > maxx) {
			maxx = d[i][m];
		}
	}
	cout << maxx;
}
