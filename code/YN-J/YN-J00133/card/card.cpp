#include <bits/stdc++.h>
using namespace std;
int a[500005], p[500005], sum[500005], b[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, f = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int pd = 1;
		for (int j = 1; j <= f; j++) {
			if (a[i] == b[j])
				pd = 0;
		}
		if (pd == 1) {
			f++;
			b[f] = a[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		int t = 0, pd = 0, w;
		for (int j = i; j <= n; j++) {
			w = t;
			for (int k = 1; k <= t; k++) {
				if (a[j] == p[k]) {
					pd = 1;
					w = k;
				}
				if (pd == 1) {
					p[k] = 0;
				}
			}
			t = w;
			t++;
			p[t] = a[j];
		}
		for (int k = 1; k <= t; k++) {
			sum[p[k]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << sum[b[i]] << " ";
	}
	return 0;
}
