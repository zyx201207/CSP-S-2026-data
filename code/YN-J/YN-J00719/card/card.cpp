#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500020];
int b[500020];
int c[300020];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		int ans = i;
		for (int j = ans; j <= m; j++) {
			for (int t = i; t < j; t++) {
				if (b[t] == 0) {
					ans = t + 1;
					for (int ii = t; ii < j; ii++)
						b[ii] = 0;
					b[t] = b[j];
					break;
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			c[b[j]]++;
		}
		for (int j = 1; j <= n; j++) {
			b[j] = a[j];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << ' ';
	}
	return 0;
}