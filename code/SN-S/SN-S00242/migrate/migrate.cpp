#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e6+10;
ll C, T;
ll n, d;
ll x[N];
ll dis[N];
bool vis[N];
ll cnt[N];
vector<int> g[N];
map<int, int> dfs_vis;
ll bfs(ll s, ll e)
{
	memset(dis, 0, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	
	queue<ll> q;
	q.push(s);
	while(q.size()){
		ll x = q.front();
		q.pop();
		if(x == e){
			return dis[e];
		}
		for(ll y:g[x]){
			if(vis[y]) continue;
			vis[y] = true;
			dis[y] = dis[x]+1;
			q.push(y);
		}
	}
	return dis[e];
}
bool dfs(ll x, ll e, ll dist){
	if(dist == 0) return true;
	for(ll y:g[x]){
		cnt[y]++;
		if(cnt[e] > 2) return false;
		if(dfs_vis.find(y) != dfs_vis.end() && dfs_vis[y] >= dist){
			continue;
		}
		dfs_vis[y] = dist-1;
//		cout << "dfs(" << x << ", " << dist << ") -> dfs(" << y << ", " << dist-1 << ")\n";
		bool flag = dfs(y, e, dist-1);
		if(flag == false) return false;
	}
	return true;
}
bool check(ll s, ll e, ll dist)
{
	if(dist == 1) return false;
	if(abs(s-e) > 2*dist) return false;
	// 采用dfs
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	dfs_vis.clear();
	cnt[s]++;
	dfs_vis[s] = 0;
	int flag = dfs(s, e, dist);
	if(flag == false) return false;
	if(cnt[e] == 2) return true;
	return false;
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> C >> T;
	while(T--){
		memset(x, 0, sizeof(x));
		memset(vis, 0, sizeof(vis));
		memset(cnt, 0, sizeof(cnt));
		memset(dis, 0, sizeof(dis));
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> x[i];
		// 构建邻接表 
		for(int i=1;i<=n;i++){
			// 向右看
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i] > d) break;
				g[i].push_back(j);
				g[j].push_back(i);
			} 
		}
		
//		for(int i=1;i<=n;i++){
//			cout << "g[" << i << "] : ";
//			for(int j:g[i]){
//				cout << j << " ";
//			}
//			cout << "\n";
//		}
		
		ll ans = 0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ll distance = bfs(i, j);
//				cout << "bfs(" << i << ", " << j << ") : " << distance << "\n";
				ll checkreturn = check(i, j, distance);
//				cout << "check(" << i << ", " << j << ", " << distance << ") : " << checkreturn << "\n";
				if(checkreturn) ans++;
			}
		}
		cout << ans << "\n";
		
//		cout<< "\n\n\n";
	}
	return 0;
}

