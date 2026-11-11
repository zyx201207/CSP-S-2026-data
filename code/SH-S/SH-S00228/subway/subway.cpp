#include<bits/stdc++.h>
#define PII pair<int, int>
#define int long long
using namespace std;
const int N = 1e6 + 9;
vector<PII> edges[N];
int w[N];
int dis[N];
bool vis[N];
int c, n, m, d, q, x, y;
void dij(int s){
	dis[s] = 0;
	priority_queue<PII> q;
	vis[s] = 1;
	q.push({0, s});
	while(q.size()){
		PII now = q.top();
		q.pop();
		for(auto v : edges[now.second]){
			int to = v.second;
			int tm = v.first;
			if(vis[to]) continue;
			if(dis[to] > now.first + tm){
				dis[to] = now.first + tm;
				vis[now.second] = 1;
				q.push({dis[to], to});
			}
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	int idx = m + 1;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++){
		int k;
		cin >> k;
		int a, t;
		cin >> a >> t;
		edges[a].push_back({t, idx});
		edges[idx++].push_back({t, a});
		for(int j = 2; j <= k; j++){
			cin >> a >> t;
			edges[idx].push_back({0, idx - 1});
			edges[idx - 1].push_back({0, idx});
			edges[idx].push_back({t, a});
			edges[a].push_back({t, idx++});
		}
	}
	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		memset(dis, 0x3f3f3f3f, sizeof dis);
		memset(vis, 0, sizeof vis);
		dij(x);
		cout << dis[y] + w[x] + w[y];
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
