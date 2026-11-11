#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 510, M = 410, M2 = 1010;
const ll INF = 0x4f4f4f4f4f4f4f4f;

struct Edge {
	int v, num, w;
};

struct Node {
	int pos, line;
};

struct Edge2 {
	int v, w;
};

vector<Edge> G[M][N];
int c, n, m, d, q, w[M];
ll dis[M][N], dis2[M2][M2];
vector<Edge2>G2[M];

void dij(int st) {
	memset(dis, INF, sizeof(dis));
	dis[st][0] = 0;
	queue<Node>q;
	q.push({st, 0});
	while (!q.empty()) {
		Node u = q.front();
		q.pop();
		int pos = u.pos, line = u.line;
		for (int i = 0; i < G[pos][line].size(); i ++) {
			Edge e = G[pos][line][i];
			Node v = {e.v, e.num};
			if (e.w + dis[pos][line] < dis[e.v][e.num]) {
				q.push(v);
				dis[e.v][e.num] = e.w + dis[pos][line];
			}
		}
	}
	return;
}

void dij2(int st) {
	dis2[st][st] = 0;
	queue<int>q;
	q.push(st);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < G2[u].size(); i ++) {
			int v = G2[u][i].v;
			if (dis2[st][v]>dis2[st][u]+G2[u][i].w) {
				dis2[st][v]=dis2[v][st]=dis2[st][u]+G2[u][i].w;
				q.push(v);
			}
		}
	}
	return;
}

void solve1() {
	memset(dis2, INF, sizeof(dis2));
	for (int i = 1; i <= m; i ++) {
		cin>>w[i];
	}
	for (int i = 1; i <= n; i ++) {
		int k, prea, pret;
		cin>>k;
		for (int i = 1; i <= k; i ++) {
			int a, t;
			cin>>a>>t;
			if (k==1) continue;
			if (i==2) {
				G2[a].push_back({prea, pret+t});
				G2[prea].push_back({a, pret+t});
			} 
			prea = a, pret = t;
		}
	}
	for (int i = 1; i <= q; i ++) {
		int x, y;
		cin>>x>>y;
		if (dis2[x][y]==INF) dij2(x);
		cout<<dis2[x][y]+w[x]+w[y]<<endl;
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	if (9<=c&&c<=11) {
		solve1();
		return 0;
	}
	for (int i = 1; i <= m; i ++) {
		cin>>w[i];
	}
	for (int i = 1; i <= n; i ++) {
		int k, pre;
		cin>>k;
		for (int j = 1; j <= k; j ++) {
			int a, t;
			cin>>a>>t;
			G[a][i].push_back({a,0,t});
			G[a][0].push_back({a,i,t});
			if (j>=2) {
				G[a][i].push_back({pre,i,0});
				G[pre][i].push_back({a,i,0});
			}
			pre = a;
		}
	}
	for (int i = 1; i <= q; i ++) {
		int x, y;
		cin>>x>>y;
		dij(x);
		cout<<dis[y][0]+w[x]+w[y]<<endl;
	}
	return 0;
}
