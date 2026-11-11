#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 907777111;

struct node {
	int to, t;
};

const ll N = 514514;
int c, d, q, n, m, ans;
int w[N], dis[500][500];
vector<node>p[N];

void add(int u, int v, int w) {
	p[u].push_back({v, w});
	p[v].push_back({u, w});
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int a[1009], t[1009];
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
			add(a[j - 1], a[j], t[j - 1]);
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			dis[i][j] = inf, dis[i][i] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			dis[i][j] = min(dis[i][j], dis[i][j - 1] + p[i][j].t + p[j][i].t);
	for (int i = 1; i <= q; i++) {
		int a, b;
		cin >> a >> b;
		cout << w[a] + w[b] + dis[a][b] << "\n";
	}
	return 0;
}
