#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e4+5, Q = 1e5+5;
int c, n, m, d, q, k[N], a[N][M], l, r, nu[M], b[M][N];
long long w[M], t[N][M], ans, sum, T;
bool pn[N], pm[M], pp[N][M];

void dfs(int now) {
	if (now == r) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 1; i <= nu[now]; i++) {
		int x = b[now][i];
		if (pn[x])
			continue;
		sum += t[x][now];
		pn[x] = 1;
		for (int j = 1; j <= k[x]; j++) {
			if (!pm[a[x][j]]) {
				sum += t[x][a[x][j]];
				pm[a[x][j]] = 1;
				dfs(a[x][j]);
				sum -= t[x][a[x][j]];
				pm[a[x][j]] = 0;
			}
		}
		sum -= t[x][now];
		pn[x] = 0;
	}
}

void dfs2(int now) {
	if (now == r) {
		ans = min(ans, sum);
		return;
	}
	for (int i = 1; i <= nu[now]; i++) {
		int x = b[now][i];
		if (pn[x])
			continue;
		sum += T;
		pn[x] = 1;
		if (pp[x][r]) {
			sum += T;
			dfs2(r);
			return;
		}
		for (int j = 1; j <= k[x]; j++) {
			if (!pm[a[x][j]]) {
				sum += T;
				pm[a[x][j]] = 1;
				dfs(a[x][j]);
				sum -= T;
				pm[a[x][j]] = 0;
			}
		}
		sum -= T;
		pn[x] = 0;
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("subway1.in", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		if (k[i] == 1) {
			cin >> a[i][1] >> t[i][a[i][1]];
			n--;
			i--;
			continue;
		}
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][a[i][j]];
			b[a[i][j]][++nu[a[i][j]]] = i;
		}
	}
	bool p = 1;
	T = t[1][a[1][1]];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {
			if (t[i][a[i][j]] != T) {
				p = 0;
				break;
			}
		}
		if (!p)
			break;
	}
	if (p) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k[i]; j++) {
				pp[i][a[i][j]] = 1;
			}
		}
		for (int i = 1; i <= q; i++) {
			cin >> l >> r;
			ans = 0x3f3f3f3f3f3f3f3f;
			sum = w[l] + w[r];
			pm[l] = 1;
			dfs2(l);
			cout << ans << '\n';
			pm[l] = 0;
		}
		return 0;
	}
	for (int i = 1; i <= q; i++) {
		cin >> l >> r;
		ans = 0x3f3f3f3f3f3f3f3f;
		sum = w[l] + w[r];
		pm[l] = 1;
		dfs(l);
		cout << ans << '\n';
		pm[l] = 0;
	}
	return 0;
}
