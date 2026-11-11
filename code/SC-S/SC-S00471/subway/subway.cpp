#include <bits/stdc++.h>
#define PII pair<long long, long long>
using namespace std;

const int N = 6e5 + 1000;

int C, n, m, d, T;
long long goin[N], k[510];
vector<PII> ed[N];
bool vis[N];
long long dis[N];
int dis2[2000][2000];
bool ge[N];
long long dp[N];
void clean()
{
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
}
void dijkstra(int S)
{
	clean();
	priority_queue<PII, vector<PII>, greater<PII>> que;
	dis[S] = 0;
	que.push({0, S});
	while(!que.empty()){
		int u = que.top().second; que.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto x : ed[u]){
			long long v = x.first, w = x.second;
			if(dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				que.push({dis[v], v});
			}
		}
	}
}
void dijkstra2(int S)
{
	ge[S] = true;
	memset(dis2[S], 0x3f, sizeof dis2[S]);
	memset(vis, 0, sizeof vis);
	priority_queue<PII, vector<PII>, greater<PII>> que;
	dis2[S][S] = 0;
	que.push({0, S});
	while(!que.empty()){
		int u = que.top().second; que.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto x : ed[u]){
			long long v = x.first, w = x.second;
			if(dis2[S][v] > dis2[S][u] + w){
				dis2[S][v] = dis2[S][u] + w;
				que.push({dis2[S][v], v});
			}
		}
	}
}
void test16()
{
	cin >> n >> m >> d >> T;
	for(int i = 1; i <= m; i ++ ) cin >> goin[i];
	for(int i = 1; i <= n; i ++ ){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++ ){
			long long u, w, v = i + m;
			cin >> u >> w;
			ed[u].push_back({v, w});
			ed[v].push_back({u, w});
		}
	}
	while(T -- ){
		int s, t; cin >> s >> t;
		dijkstra(s);
		cout << dis[t] + goin[s] + goin[t] << endl;
	}
}
void test711()
{
	cin >> n >> m >> d >> T;
	for(int i = 1; i <= m; i ++ ) cin >> goin[i];
	for(int i = 1; i <= n; i ++ ){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++ ){
			long long u, w, v = i + m;
			cin >> u >> w;
			ed[u].push_back({v, w});
			ed[v].push_back({u, w});
		}
	}
	
	int head = 0;
	for(int i = 1; i <= m + n; i ++ ){
		if(ed[i].size() == 1){
			head = i;
			break;
		}
	}
	
	dijkstra(head);
	
	while(T -- ){
		int u, v; cin >> u >> v;
		cout << abs(dis[u] - dis[v]) << endl;
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> C;
	if(C >= 1 && C <= 6){
		test16();
		return 0;
	}
	
	if(C >= 7 && C <= 11){
		test711();
		return 0;
	}
	
	cin >> n >> m >> d >> T;
	for(int i = 1; i <= m; i ++ ) cin >> goin[i];
	for(int i = 1; i <= n; i ++ ){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++ ){
			long long u, w, v = i + m;
			cin >> u >> w;
			ed[u].push_back({v, w});
			ed[v].push_back({u, w});
		}
	}
	
	while(T -- ){
		int s, t; cin >> s >> t;
		if(t > s) swap(t, s);
		if(ge[s] == false){
			dijkstra2(s);
		}
		cout << dis2[s][t] + goin[s] + goin[t] << endl;
	}
	
	return 0;
}