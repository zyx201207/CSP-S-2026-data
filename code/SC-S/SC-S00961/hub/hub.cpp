#include <bits/stdc++.h>
using namespace std;

//#define DEBUG
const int N = 1e6 + 6;
int n, k;
vector<int> E[N];
bool vis[N], now[N];
int dis[N];
queue<int> q;

void dfs(int u) {
	if(!now[u])return ;
	vis[u] = 1;
	for (int i : E[u]) {
		if(!vis[i] && now[i])dfs(i);
	}
}

int bfs() {
	for (int i = 1; i <= n; ++i)if(!dis[i])q.push(i);
	int mx = 0;
	while(q.size()) {
		int u = q.front();
		q.pop();
		mx = dis[u];
		for (int i : E[u]) {
			if(dis[i] > dis[u] + 1) {
				dis[i] = dis[u] + 1;
				q.push(i);
			}
		}
	}
	return mx;
}

int chk(int td) {
	int ct = 0;
	for (int i = 1; i <= n; ++i) {
		dis[i] = N;
		if((td >> (i - 1)) & 1) {
			now[i] = 1;
			dis[i] = 0;
			++ct;
		}else now[i] = 0;
		vis[i] = 0;
	}
	if(ct != k)return N;
	int scc = 0;
	for (int i = 1; i <= n; ++i)if(now[i] && !vis[i])++scc, dfs(i);
	if(scc > 2)return N;
//	cout << '\n';
	int a = bfs();
//	if(a == 1) {
//		cout << "   ";
//		for (int i = 1; i <= n; ++i) {
//			if((td >> (i - 1)) & 1) {
//				cout<<  i << ' ';
//			}
//		}
//		cout << '\n';
//	}
	return a;
}

void slv() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)E[i].clear();
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	int U = 1 << n;
	int ans = N;
	for (int i = 1; i < U; ++i) ans = min(ans, chk(i));
	printf("%d\n", ans);
}

int main() {
#ifndef DEBUG
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
#endif
	int T;
	scanf("%d%d", &T, &T);
	while(T--)slv();
	return 0;
}