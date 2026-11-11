#include <bits/stdc++.h>
#define FILE(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
#define DEBUG(s) freopen(s".err", "w", stderr)
#define CloseFILE fclose(stdin), fclose(stdout)
#define CloseDEBUG fclose(stderr)
#define pii pair<int, int>
#define int long long
#define endl "\n"
using namespace std;

constexpr int MAXN = 505, MAXM = 5e5+5;
int c, n, m, d, q, x, y, dis[MAXM][25], vis[MAXM][25], k[MAXN], w[MAXM];
vector<pii> a[MAXN];
unordered_map<int, vector<pii> > mp;
unordered_map<int, int> mp2[MAXM];

struct node {
	int dist, u, line; bool transfer, way;
	// way：1 左 -> 右，0 左 <- 右 
	bool operator < (const node &b) const {
		return dist > b.dist;
	}
};

int dijkstra() {
	memset(dis, 0x3f, sizeof(dis));
//	memset(vis, 0, sizeof(vis));
	priority_queue<node> q;
	for (pii s : mp[x]) {
		q.push({a[s.first][s.second].second,x,s.first,1,0});
		q.push({a[s.first][s.second].second,x,s.first,1,1});
		vis[x][s.first] = 1;
		dis[x][s.first] = a[s.first][s.second].second*2;
	}
	while (!q.empty()) {
		node t = q.top();
		int dist = t.dist, u = t.u, line = t.line;
		bool transfer = t.transfer, way = t.way; q.pop();
		int pos = lower_bound(mp[u].begin(), mp[u].end(), (pii){line, 0}) - mp[u].begin();
		pos = mp[u][pos].second;
//		cout << line << " " <<pos << endl;
		int tij = a[line][pos].second;
//		cout << dist << " " << u << " " << line <<" " << transfer << " " <<way<<endl;
		if (dist+tij != dis[u][line]) {
//			cout << "jwj" << " "<<dist+tij <<" " << dis[u][line] << endl;
			continue;
		}
//		if (vis[u][line]) continue;
//		vis[u][line] = 1;
		if (u == y) return dis[u][line];
		if (!transfer) {
//			cout << "awa" << dist << " " << u << " " << line <<" " << transfer << " " <<way<<endl;
			for (pii gg : mp[u]) {
				int line2 = gg.first, tij2 = a[gg.first][gg.second].second;
				if (line == line2) continue;
				if (dist+tij+tij2 < dis[u][line2]) {
					dis[u][line2] = dist+tij+tij2*2;
					q.push({dist+tij+tij2,u,line2, 1, 0});
					q.push({dist+tij+tij2,u,line2, 1, 1});
				}
			}
		}
		if (way && pos < (int)a[line].size()-1) {
			if (dis[a[line][pos+1].first][line] > dist+a[line][pos+1].second) {
				dis[a[line][pos+1].first][line] = dist+a[line][pos+1].second;
				q.push({dist,a[line][pos+1].first,line, 0, way});
			}
		} else if ((!way) && pos > 0) {
			if (dis[a[line][pos-1].first][line] > dist+a[line][pos-1].second) {
				dis[a[line][pos-1].first][line] = dist+a[line][pos-1].second;
				q.push({dist,a[line][pos-1].first,line, 0, way});
			}
		}
	} 
	return -1; // 题目保证有解哦 
}

signed main() {
	FILE("subway"), DEBUG("subway");
	cin.tie(0) -> sync_with_stdio(0);
//	cout <<1+1;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int aij, tij;
			cin >> aij >> tij;
			a[i].push_back({aij, tij});
			mp[aij].push_back({i, j-1});
		}
	}
	// 进出两站的时间最后加上 
	while (q--) {
		cin >> x >> y;
		cout << dijkstra()+w[x]+w[y] <<endl;
	}


//	CloseFILE, CloseDEBUG;
	return 0;
}
// 要是把上海地铁线路图当做输入数据，这样就可以手搓导航系统了 
