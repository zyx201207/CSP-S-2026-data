#include <bits/stdc++.h>
#define int long long
#define fp(i,a,b) for(int i=a;i<=b;i++)
#define pf(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

constexpr int MN = 5e5+510, MM = 5e5+10;
int cas, n, m, W[MN], tot, bfsw;
vector<pair<int, int>> G[MN];

int vis[MN];
int bfs(int s, int t) {
	fp(i,1,n+m) vis[i] = 0;
	queue<pair<int, int>> q;
	q.push({s, 0}); vis[s] = 1;
	while(!q.empty()) {
		pair<int, int> kkk = q.front(); q.pop();
		int &u = kkk.first, &stp = kkk.second;
		for(pair<int, int> qwq:G[u]) {
			int const& v = qwq.first;
			if(vis[v]) continue;
			vis[v] = 1;
			q.push({v, stp + 1});
			if(v == t) {
				return (stp + 1) * bfsw;
			}
		}
	}
}

int dis[MN];
void dijkstra(int s) {
	fp(i,1,n+m) dis[i] = 1e18, vis[i] = 0;
	dis[s] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({dis[s], s});
	while(!q.empty()) {
		int u = q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(pair<int, int> qwq:G[u]) {
			int const& v = qwq.first;
			int const& w = qwq.second;
			if(vis[v]) continue;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
}

void awa() {
	int x, y;
	cin>>x>>y;
	if(12 <= cas && cas <= 19) {
		cout<<bfs(x, y) + W[x] + W[y]<<endl;
	}
	
	else {
//		cout<<rand()%11451419<<endl;
		dijkstra(x);
		cout<<dis[y] + W[x] + W[y]<<endl;
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	srand(time(0));
	int d, q, k, a, t;
	cin>>cas>>n>>m>>d>>q; tot = m;
	fp(i,1,m) cin>>W[i];
	fp(i,1,n) {
		cin>>k;
		if(k <= 1) continue;
		if(7 <= cas && cas <= 11) {
			int b, c, d;
			cin>>a>>b>>c>>d;
			G[a].push_back({c, b+d});
			G[c].push_back({a, b+d});
		} else {
			tot ++;
			fp(i,1,k) {
				cin>>a>>t; bfsw = t;
				G[tot].push_back({a, t});
				G[a].push_back({tot, t});
			}
		}
	}
	while(q--) awa();
	return 0;
}