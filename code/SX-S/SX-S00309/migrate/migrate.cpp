#include <bits/stdc++.h>
using namespace std;
int x[2000010], n, d;
int c, t;
int dis[50000];

void dfs(int last, int r, int cnt) {
	if (last == r) {
		dis[cnt]++;
	}
	for (int i = 1; last + i <= r; i++) {
		if (x[last + i] - x[last] <= d) {
			dfs(last + i, r, cnt + 1);
		}

	}
	return ;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		sort(x + 1, x + n + 1);
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				memset(dis, 0, sizeof(dis));
				dfs(i, j, 0);
				for (int k = 1; k <= j - i; k++) {
					if (dis[k] != 0) {
						if (dis[k] == 2) {
							ans++;
//							cout << i << " " << j  << " " << k << endl;
						}
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
