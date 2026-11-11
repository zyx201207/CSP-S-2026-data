#include <bits/stdc++.h>
using namespace std;
const int MAXM = 100005;
long long c, n, m, d, q, dis[MAXM], edgenum[MAXM], zhan[MAXM];
vector<pair<int, int>> edge[MAXM];

void dijkstra(int s) {

	bool vis[MAXM];
	long long  minn, minp;
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	minn = s;
	minp = 0x3f3f3f3f3f;
	for (int relax = 1; relax <= m; relax++) {

		minp = 0x3f3f3f3f;
		int cur = minn;
		vis[cur] = 1;
		for (int j = 0; j < edgenum[cur]; j++) {
			dis[edge[cur][j].first] = min(edge[cur][j].second + dis[cur], dis[edge[cur][j].first]);
		}
		for (int i = 1; i <= m; i++) {
			if (dis[i] < minp && vis[i] != 1) {
				minp = dis[i];
				minn = i;
			}
		}


	}

}

void add(int a, int b, int cc) {
	//cout << "make " << a << "<->" << b << " weight:" << cc << endl;
	edge[a].push_back(make_pair(b, cc));
	edge[b].push_back(make_pair(a, cc));
	edgenum[a]++;
	edgenum[b]++;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T;
	cin >> T >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> zhan[i];
	}
	for (int i = 1; i <= n; i++) {
		int k, mo[MAXM], wo[MAXM];
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> mo[j] >> wo[j];
		}
		for (int j = 1; j < k; j++) {
			for (int jj = j + 1; jj <= k; jj++) {
				add(mo[j], mo[jj], wo[j] + wo[jj]);
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int start, end;
		cin >> start >> end;
		dijkstra(start);
		cout << dis[end] + zhan[start] + zhan[end] << endl;
	}

	return 0;
}
