#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n,dis[600010],vis[600010];
vector<pair<int,int>> g[600010];
vector<int> tag;
void dijkstra(int s){
	priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,
	greater<tuple<int,int,int>>> q;
	q.emplace(0,s,0);
	dis[s] = 0,vis[s] = 1;
	tag.emplace_back(s);
	while (q.size()){
		int u = get<1>(q.top()),cnt = get<2>(q.top());
		q.pop();
		for (auto i : g[u]){
			int v = i.second,w = i.first;
			if (dis[v] > dis[u] + w && !vis[v] && cnt < 2 * n){
				vis[v] = true;
				dis[v] = dis[u] + w;
				q.emplace(w,v,cnt + 1);
				tag.emplace_back(v);
			}
		}
	}
}
void bfs(int s){
	queue<pair<int,int>> q;
	q.emplace(s,0);
	dis[s] = 0,vis[s] = 1;
	tag.emplace_back(s);
	while (q.size()){
		int u = q.front().first,cnt = q.front().second;
		q.pop();
		for (auto i : g[u]){
			int v = i.second,w = i.first;
			if (!vis[v] && cnt < 2 * n){
				vis[v] = true;
				dis[v] = dis[u] + w;
				q.emplace(v,cnt + 1);
				tag.emplace_back(v);
			}
		}
	}
}
int w[500010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int c,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
		cin >> w[i];
	for (int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++){
			int a,t;
			cin >> a >> t;
			g[a].emplace_back(t,i + m);
			g[i + m].emplace_back(t,a);
		}
	}
	memset(dis,0x3f,sizeof dis);
	while (q--){
		int x,y;
		cin >> x >> y;
		if (12 <= c <= 19)
			bfs(x);
		else
			dijkstra(x);
		cout << dis[y] + w[x] + w[y] << endl;
		while (tag.size()){
			dis[tag.back()] = 0x3f3f3f3f3f3f3f3fll;
			vis[tag.back()] = 0;
			tag.pop_back(); 
		}
	}
	return 0;
}

