#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int c, n, m, d, q, w[500003], k[503];
long long dis[500503];
bool vis[500503];
vector<pair<int, int> > e[500503];

void dij(int st, int en){
	for (int i = 1; i <= n + m; i++){
		dis[i] = 1e18 + 3;
		vis[i] = 0;
	}
	dis[st] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push({0, st});
	while (!q.empty()){
		pair<int, int> now = q.top();
		q.pop();
		if (vis[now.second]){
			continue;
		}
		vis[now.second] = 1;
		for (auto i : e[now.second]){
			if (dis[i.first] > dis[now.second] + i.second){
				dis[i.first] = dis[now.second] + i.second;
				q.push({dis[i.first], i.first});
			}
		}
	}
	cout << dis[en] + w[st] + w[en] << "\n";
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++){
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++){
			int a, t;
			cin >> a >> t;
			e[m + i].push_back({a, t});
			e[a].push_back({m + i, t});
		}
	}
	for (int i = 1; i <= q; i++){
		int st, en;
		cin >> st >> en;
		dij(st, en);
	}
	return 0;
}