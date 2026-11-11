#include <bits/stdc++.h>
using namespace std;
long long a[200005], maxx = -1;
int b[35], c[200005][35];
int n, m;

void dfs(int x, int y) {
	if (x > m) {
		long long maxn = 0;

		for (int j = 1; j <= 30; j++)

			if (b[j] == 1)
				maxn += pow(2, j - 1);
		maxx = max(maxx, maxn);
		return ;
	}

	for (int i = y + 1; i <= n - m + x; i++) {

		int d[35];

		for (int j = 1; j <= 30; j++)

			d[j] = b[j];

		if (x == 1)
			for (int j = 1; j <= 30; j++)

				b[j] = c[i][j];
		else
			for (int j = 1; j <= 30; j++)

				b[j] = (c[i][j] && b[j]);
		dfs(x + 1, i);

		for (int j = 1; j <= 30; j++)

			b[j] = d[j];
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		int j = 31;
		long long p = a[i], x = 1024 * 1024 * 1024;

		while (p > 0) {
			if (p >= x) {
				c[i][j] = 1;
				p -= x;
			}

			j--;
			x /= 2;
		}
	}

	dfs(1, 0);
	cout << maxx;
	return 0;
}