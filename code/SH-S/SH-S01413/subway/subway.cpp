/*

”÷À¿»•¡À 

*/


//#include <iostream>
//#include <cstring>
//#include <vector> 
//#include <queue>
//
//using namespace std;
//
//const int M = 5e5 + 10;
//const int N = 5e2 + 10;
//
//int Ccc, n, m, d, q;
//
//int dis[N];
//bool vis[N];
//
//struct node {
//	int y, w, id;
//	bool operator < (const node &u) const {
//		return u.w < w;
//	}
//};
//
//int w[M], arr[N];
//vector<node> G[N];
//
//void dijkstra(int s) {
//	memset(dis, 0x3f, sizeof dis);
//	priority_queue<node> q;
//	q.push({0, s, 0});
//	dis[s] = 0;
//	while (!q.empty()) {
//		int x = q.top().y, idx = q.top().id;
//		q.pop();
//		if (vis[x]) continue;
//		vis[x] = 1;
//		for (auto now : G[x]) {
//			int y = now.y, w = now.w, idy = now.id;
//			if (idx == idy) {
//				if (dis[y] > dis[x] + w) {
//					dis[y] = dis[x] + w;
//					if (!vis[y]) q.push({y, dis[y], idy});
//				}
//			} else {
//				if (dis[y] > dis[x] + arr[idy] + w * (x != 0)) {
//					dis[y] = dis[x] + w + arr[idy]* (x != s);
//					if (!vis[y]) q.push({y, dis[y], idy});
//				}
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> Ccc >> n >> m >> d >> q;
//	for (int i = 1; i <= m; i++)
//		cin >> w[i];
//	for (int i = 1; i <= n; i++) {
//		int ki, ai, ti, lst;
//		cin >> ki >> ai >> ti;
//		lst = ai;
//		arr[i] = ti;
//		G[0].push_back({ai, ti, i});
//		G[ai].push_back({0, ti, i});
//		for (int j = 2; j <= ki; j++) {
//			cin >> ai >> ti;
//			G[lst].push_back({ai, ti, i});
//			G[ai].push_back({lst, ti, i});
//		}
//	}
//	while (q--) {
//		int l, r;
//		cin >> l >> r;
//		dijkstra(l);
//		cout << dis[r] << "\n";
//	}
//	return 0;
//}

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int M = 1e3 + 10;

int Ccc, n, m, d, q, l, r;
int w[M],f[M];
bool flag;
vector<int> G[M];
int t[M][M], dis[510];
map<pair<int, int>,int> mp;

void dfs(int l) {
	if (flag) dis[l] = t[0][l], flag = 0;
	for (auto y : G[l]) {
		dfs(y);
		dis[l] = min(dis[l], dis[y] + t[l][y]+(f[y] && f[y]!=mp[{l,y}])*t[0][y]);
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
	cin >> Ccc >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		int ki, ai, ti;
		cin >> ki;
		int lst = 0;
		for (int j = 1; j <= ki; j++) {
			cin >> ai >> t[lst][ai];
			if (j==1)f[ai]=i;
			mp[{lst,ai}]=mp[{ai,lst}]=i;
			G[lst].push_back(ai);
			lst = ai;
		}
	}
	while (q--) {
		cin >> l >> r;
		flag = 0;
		for (auto ddd : G[0]) if (ddd == l) {
			flag = 1;
			break;
		}
		memset(dis, 0x3f, sizeof dis); 
		dfs(l);
		cout << dis[r]+w[l]+w[r]<<"\n";
	}
	return 0;
}
