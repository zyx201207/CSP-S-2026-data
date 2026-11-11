#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

const int N = 5e2 + 10;
const int M = 5e5 + 10;
const int D = 30;
const LL inf = 0x3f3f3f3f3f3f3f3f;

int c, n, m, d, q;
int w[M];
int num[M], line[M][D];
int k[N], a[M];
LL tt[M], t[M][D];
LL dist[N][N], st[N];

void upd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int t = 1; t <= n; t++) {
				dist[i][j] = min(dist[i][j], dist[i][t] + dist[t][j]);
			}
		}
	}
}

LL checkAns(int x, int y) {
	LL ans = inf;
	for (int i = 1; i <= num[x]; i++) {
		for (int j = 1; j <= num[y]; j++) {
			ans = min(ans, t[x][i] + dist[line[x][i]][line[y][j]] + t[y][j]);
		}
	}
	return ans + w[y] + w[x];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dist[i][j] = inf;
		dist[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[j] >> tt[j];
			for (int x = 1; x <= num[a[j]]; x++) {
				dist[i][line[a[j]][x]] = min(dist[i][line[a[j]][x]], t[a[j]][x] + tt[j]);
				dist[line[a[j]][x]][i] = min(dist[line[a[j]][x]][i], tt[j] + t[a[j]][x]);
			}
			line[a[j]][++num[a[j]]] = i;
			t[a[j]][num[a[j]]] = tt[j];
		}
	}
	upd();
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << checkAns(x, y) << '\n';
	}
	return 0;
}