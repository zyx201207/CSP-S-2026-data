#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int c,n,m,d,q;
int w[N];
int a[505][N];
int t[505][N];
int k[N];
int dis[N];
bool vis[N];
void dj(int n) {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(n,0));
	dis[n] = 0;
	//vis[u] = 1;
	while(!pq.empty()) {
		pair<int,int> ed = pq.top();
		pq.pop();
		int u = ed.first;
		int w = ed.second;
		if(vis[u]) {
			continue;
		}
		vis[u] = 1;
		for(int i = 1; i <= k[u]; i++) {
			int v = a[u][i];
			if(dis[v] > dis[u] + t[u][v]) {
				dis[v] = dis[u] + t[u][v];
				pq.push(make_pair(v,t[u][v]));
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1; i <= q; i++) {
		int x,y;
		cin >> x >> y;
		dj(x);
		cout << w[x]+w[y]+dis[y] << "\n";
	}
	return 0;
}

