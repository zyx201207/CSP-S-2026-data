#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, p;
int w[101000], k[100100], a[1010][1010], t[1010][1010], b[1010][1010];
int mi = INT_MAX;

void dfs(int x, int y, int sum) {
	if (x == y) {
		mi = min(mi, sum);
		return ;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (a[i][j] == x) {
				b[i][j] = 1;
				for (int l = 1; l <= k[i]; l++) {
					if (b[i][l] != 1) {
						b[i][l] = 1;
						dfs(a[i][l], y, sum + t[i][l] + t[i][j]);
						b[i][l] = 0;
					}
				}
				b[i][j] = 0;
				break;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	int x, y;
	for (int i = 1; i <= p; i++) {
		cin >> x >> y;
		dfs(x, y, 0);
		int sum = w[x] + w[y] + mi;
		cout << sum << endl;
	}

	return 0;
}
