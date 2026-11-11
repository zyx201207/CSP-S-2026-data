#include <bits/stdc++.h>

using namespace std;
const int N = 2000, M = 1e6;

typedef long long ll;


int c, lin, n, d, Q, m;
ll w[N];

ll a[N], t[N], tt;
ll e[N][N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(e, 0x3f, sizeof e);

	cin >> c >> lin >> n >> d >> Q;

	for (int i = 1; i <= n; i++)
		e[i][i] = 0;

	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}

	for (int i = 1; i <= lin; i++) {
		cin >> tt;
		for (int j = 1; j <= tt; j++) {
			cin >> a[j] >> t[j];
		}

		for (int j = 1; j < tt; j++) {
			for (int r = j + 1; r <= tt; r++) {
				e[a[j]][a[r]] = min(e[a[j]][a[r]], t[j] + t[r]);
				e[a[r]][a[j]] = min(e[a[r]][a[j]], t[j] + t[r]);
			}
		}
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
			}
		}
	}

	int lx, ry;
	while (Q--) {
		cin >> lx >> ry;
		cout << w[lx] + w[ry] + e[lx][ry] << endl;
	}
	return 0;
}

