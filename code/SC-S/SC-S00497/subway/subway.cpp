#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int N = 5e2 + 5, M = 5e5 + 5, D = 25;
const ll inf = 1e18;
int fvv, n, m, d, q;
ll w[M];

int k[N];

vector <pair <int, ll>> psd[M];

ll dis[N][N];

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> fvv >> n >> m >> d >> q;
	for (int i = 1; i <= n; ++ i)
	for (int j = 1; j <= n; ++ j)
		if (i != j) dis[i][j] = inf;
	for (int i = 1; i <= m; ++ i) cin >> w[i];
	for (int i = 1; i <= n; ++ i) {
		cin >> k[i];
		int st, oth; ll tm, tm2;
		for (int j = 0; j < k[i]; ++ j) {
			cin >> st >> tm;
			for (auto pr : psd[st]) {
				oth = pr.first, tm2 = pr.second;
				dis[i][oth] = dis[oth][i] = min(dis[i][oth], tm + tm2);
				
			}
			psd[st].push_back(make_pair(i, tm));
		}
	}
	for (int kk = 1; kk <= n; ++ kk) {
		for (int i = 1; i <= n; ++ i) if (i != kk) {
			for (int j = i + 1; j <= n; ++ j) if (j != kk)
				dis[i][j] = dis[j][i] = min(dis[i][j], dis[i][kk] + dis[kk][j]);
		}
	}
	int x, y; ll fnl;
	for (int qi = 1; qi <= q; ++ qi) {
		cin >> x >> y;
		fnl = inf;
		for (auto pr1 : psd[x])
		for (auto pr2 : psd[y]) {
			fnl = min(fnl, dis[pr1.first][pr2.first] + pr1.second + pr2.second);
		}
		fnl += w[x] + w[y];
		cout << fnl << '\n';
	}
	return 0;
}