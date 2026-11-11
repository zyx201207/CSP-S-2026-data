#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int w[500005], a[505][50005], k[500005], t[505][50005], x, y, r, ans;
bool sub[500005];

bool check(int s, int ww) {
	for (int i = 1; i <= n && i != ww; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (a[i][j] == s)
				return true;
		}
	}
	return false;
}

void dfs(int time, int sta, int way, int ss) {
	for (int i = 1; i <= k[way]; i++) {
		if (a[way][i] == y) {
			time += t[way][i];
			ans = min(ans, time);
		}
	}
	/*	if (check(sta, way)) {
		time += t[way][ss];
		for (int i = 1; i <= n ; i++) {
			if (i == way)
				continue;
			for (int j = 1; j <= k[i]; j++) {
				if (a[i][j] == sta)
					dfs(time + t[i][j], a[i][j], i, j);
			}
		}
		time -= t[way][ss];

	}*/
	sub[a[way][ss]] = true;

	for (int i = 1; i <= k[way]; i++) {
		if (sub[a[way][i]])
			continue;
		dfs(time, a[way][i], way, i);
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];

	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}

	while (q--) {
		cin >> x >> y;
		ans = LONG_MAX;
		memset(sub, 0, sizeof(sub));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k[i]; j++) {
				if (a[i][j] == x)
					dfs(t[i][j], a[i][j], i, j);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
