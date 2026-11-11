#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+10;

typedef long long ll;

int c, t;
int n, d;
ll a[N];
ll e[N][N];
ll bian[N][N];
ll cnt, ans;
bool pan[N];

void dfs(int u, int v, int now, int w) {
	if (w > e[u][v])
		return;
	if (now == v) {
		if (w == e[u][v])
			cnt++;
		return;
	}
	for (int i = now + 1; i <= n; i++) {
		if (u != i) {
			pan[i] = 1;
			dfs(u, v, i, w + bian[now][i]);
			pan[i] = 0;
		}
	}
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (i != j) {
					if (labs(a[i] - a[j]) > d)
						e[i][j] = e[j][i] = INT_MAX;
					else
						e[i][j] = e[j][i] = 1;
				} else
					e[i][i] = 0;
			}
		}
		memcpy(bian, e, sizeof bian);

		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				cnt = 0;
				//cout << i << " " << j << " " << e[i][j] << endl;
				dfs(i, j, i, 0);
				if (cnt == 2)
					ans++;
			}
		}

		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
