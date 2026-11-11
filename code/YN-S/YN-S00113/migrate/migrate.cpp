#include <bits/stdc++.h>
using namespace std;
int c, t;
int n, d;
int a[350];
int dis[350];
int cnt[350];
int maxn = 2e9;

void dfs(int dq, int sumn, int yl) {
	if (sumn == dis[dq])
		cnt[dq]++;
	if (sumn < dis[dq]) {
		dis[dq] = sumn;
		cnt[dq] = cnt[yl];
	}
	for (int i = dq + 1; i <= n; i++) {
		if (a[i] - a[dq] <= d)
			dfs(i, sumn + a[i] - a[dq], dq);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int sumn = 0;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[j] = maxn;
				cnt[j] = -1;
			}
			dis[i] = 0;
			dfs(i, 0, i);
			for (int k = 1; k <= n; k++)
				if (cnt[k] == 2)
					sumn++;
		}
		cout << sumn << "\n";
	}
	return 0;
}