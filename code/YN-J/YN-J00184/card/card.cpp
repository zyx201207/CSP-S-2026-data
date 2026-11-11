#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], f[500005], c[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(f, 0, sizeof(f));
		int b = 1;
		for (int j = i; j <= n; j++) {
			bool g = true;
			f[b] = a[j];
			int o = b;
			for (int l = 1; l <= o - 1; l++) {
				if (g == false) {
					f[b--] = 0;
				} else if (f[b] == f[l]) {
					f[b--] = 0;
					g = false;
				}
			}
			b++;
		}/*
		for (int j = 1; j <= k - 1; j++) {
			bool g = true;
			f[b] = a[j];
			for (int l = 1; l <= b - 1; l++) {
				if (g == false) {
					f[b--] = 0;
				} else if (f[b] == f[l]) {
					f[b--] = 0;
					g = false;
				}
			}
			b++;
		}*/
		for (int i = 1; i <= b; i++) {
			//cout << f[i] << " ";
			c[f[i]]++;
		}
		//cout << endl;
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
	return 0;
}