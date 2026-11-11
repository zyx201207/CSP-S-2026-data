#include <bits/stdc++.h>
using namespace std;
int a[100005],  sum[100005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int T = n;
	while (T--) {
		int b[100005];
		for (int i = 1; i <= n; i++) {
			b[i] = 0;
		}
		for (int i = T; i <= n; i++) {
			int k = a[i];
			for (int j = 1; j <= n; j++) {
				if (a[j] == k) {
					for (int q = j; q <= n; q++) {
						b[q] = 0;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] == T)
				sum[a[i]]++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << sum[i] << " ";
	return 0;
}