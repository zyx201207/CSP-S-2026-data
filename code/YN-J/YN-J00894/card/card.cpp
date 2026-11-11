#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], b[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]] = i;
	}
	long long ans[3001];
	for (int i = 1; i <= m; i++)
		ans[i] = 0;
	for (int i = 1; i <= n; i++) {
		int c[3001];
		for (int j = 1; j <= m; j++)
			c[j] = 0;
		int j = i;
		while (j <= n) {
			if (c[a[j]] != 2)
				c[a[j]] = 1;
			if (b[a[j]] >= i) {
				for (int k = j + 1; k < b[a[j]]; k++)
					c[a[k]] = 2;
				c[a[j]] = 1;
				j =  b[a[j]] + 1;
				continue;
			}
			j = j + 1;
		}
		for (int j = 1; j <= m; j++)
			ans[j] += (c[j] == 1);
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}