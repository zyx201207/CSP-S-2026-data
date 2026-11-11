#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PP pair<int, pair<int, int>>
const int N = 500;
const int M = 5e5 + 5;
const int Q = 1e5 + 5;
int c, n, m, d, q;
int w[M], k[N];
vector<int> a[N];
map<int,int> t[N];
vector<int> g[M];
map<int,int> vis[M];
vector<int> line[M];
priority_queue<PP,vector<PP>,greater<PP>> pq;
void init() {
	for(int i = 1; i <= m; i++) {
		vis[i].clear();
	}
	while(!pq.empty()) {
		pq.pop();
	}
}
void bfs(int start,int en) {
	init();
	int ans = 0;
	for(int i : line[start]) {
		pq.push({w[start] + t[i][start], {start, i}});
	}
	while(!pq.empty()) {
		PP tmp = pq.top();
		pq.pop();
		int u = tmp.second.first;
		int dist = tmp.first;
		int lineu = tmp.second.second;
		if(u==en) {
			ans = dist + t[lineu][u];
			break;
		}
//		cout<<dist<<" "<<u<<" "<<lineu<<"\n";
		for(int v : g[u]) {
			bool flag=0;
			for(int i : line[v]) {
				if(i == lineu) {
					flag=1;
					break;
				}
			}
			if(flag == 0)
				continue;
			if(vis[u][v])
				continue;
			vis[u][v]=1;
			vis[v][u]=1;
			for(int i : line[v]) {
				if(i == lineu) {
					pq.push({dist, {v, i}});
//					cout<<dist<<" "<<u<<"->"<<v<<" "<<i<<" ==\n";
				} else {
					pq.push({dist+t[lineu][v]+t[i][v], {v, i}});
//					cout<<dist+t[lineu][v]+t[i][v]<<" "<<u<<"->"<<v<<" "<<i<<" !=\n";
				}
			}
		}
	}
	cout << ans + w[en] << "\n";
}
signed main() {
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		a[i].resize(k[i] + 1);
		for(int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][a[i][j]];
			line[a[i][j]].push_back(i);
			if(j>1) {
				g[a[i][j]].push_back(a[i][j-1]);
				g[a[i][j-1]].push_back(a[i][j]);
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		int st,en;
		cin >> st >> en;
		bfs(st,en);
	}
	return 0;
}