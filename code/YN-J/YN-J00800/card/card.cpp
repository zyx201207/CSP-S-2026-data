#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500001], b[500001], c[300001], d[300001];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[j] = c[j];
		}
		for (int j = i; j <= n; j++) {
			b[j] = 1;
			int f = 0;
			for (int s = i; s < j; s++) {
				if (a[s] == a[j] && b[s] == 1)
					f = 1;
				if (f == 1)
					b[s] = 0;
			}
		}
		for (int j = i; j <= n; j++) {
			if (b[j] == 1 && c[a[j]] == d[a[j]])
				c[a[j]]++;
		}
		for (int j = i; j <= n; j++) {
			b[j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
	return 0;
}