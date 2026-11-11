#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
int  n, c, m, d, q, k[N], dis[N], ld[N], f[N];

struct edge {
	int v, w;
} ;

//struct wqe {
//	int u, f;
//} bi[N];
int a[520][N];
vector<edge>e[N];
priority_queue<pair<int, int> > Q;
int dd[N];

void find(int x, int fa) {

//	memset(dd, 0, sizeof(dd));
	cout << x << " ";
	dd[x] = 1;
	for (int i = 0; i < e[x].size(); i++) {
		int y = e[x][i].v;
		if (dd[y])
			continue;
		find(y, x);
		cout << "\n";
	}
	return ;
}

int D(int s, int t) {
	while (!Q.empty())
		Q.pop();


	memset(dis, 0, sizeof(dis));
	memset(ld, 0x3f3f3f, sizeof(ld));
	Q.push({s, 0});
	dis[s] = 1;
	ld[s] = 0;
	while (!Q.empty()) {

		int x = Q.top().first;
//		if (dis[x])
//			continue;
		dis[x] = 1;
		Q.pop();
//		cout << 1 << "   ";
		for (int i = 0; i < e[x].size(); i++) {
			int y = e[x][i].v;

			if (!dis[y] && ld[y] > ld[x] + e[x][i].w) {

				ld[y] = ld[x] + e[x][i].w;
				Q.push({y, ld[y]});
//				dis[y] = 1;
			}

		}
	}
	return ld[t];
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		e[i].push_back({m + i, x});
		e[m + i].push_back({i, x});
	}
	int tot = 1 + 2 * m;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int x, y;
			cin >> x >> y;
			a[i][j] = x;
//			ting->dian
//			int u = x + m, v = j + 2 * m+f[i-1]*(i-1);
			e[x + 2 * m + i + j].push_back({x + m, y});
			e[x + m].push_back({x + 2 * m + j + i, y});
//			dian->dian
			if (j != 1) {
				int v = a[i][j - 1] + m + m + j - 1 + i,
				    u = a[i][j] + m + m + j + i ;
				e[u].push_back({v, 0});
				e[v].push_back({u, 0});
			}
			tot++;
		}
	}
//	find(1, 0);
	while (q--) {
		int x,  y;
		cin >> x >> y;
		cout << D(x, y) << "\n";

	}
	return 0;
}
