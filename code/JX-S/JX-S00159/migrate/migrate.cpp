#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6 + 10;
struct node{
	int v,w;
	bool operator<(const node &o) const{
		return w > o.w;
	}
};
int zkyhelpsme,T;
int n,d,p[N];
int dis[N],vis[N],cnt[N];
vector<node> g[N];
priority_queue<node> q;
void dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	dis[s] = 0,cnt[s] = 1;
	q.push({s,0});
	while(!q.empty()){
		int u = q.top().v; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0 ; i < g[u].size() ; i ++){
			int v = g[u][i].v,w = g[u][i].w;
			if(!vis[v] && dis[v] > dis[u] + w){
				dis[v] = dis[u] + w;
				cnt[v] = cnt[u];
				q.push({v,dis[v]});
			}
			else if(dis[v] == dis[u] + w)
				cnt[v] += cnt[u];
		}
	}
}
void solve(){
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i ++)
		cin >> p[i];
	for(int i = 1 ; i <= n ; i ++){
		g[i].clear();
		for(int j = i + 1 ; j <= n ; j ++)
			if(p[j] - p[i] <= d)
				g[i].push_back({j,p[j] - p[i]});
	}
	int ans = 0;
	for(int s = 1 ; s <= n ; s ++){
		dijkstra(s);
		for(int i = 1 ; i <= n ; i ++){
			if(cnt[i] == 2) ans ++;
			//cout << cnt[i] << ' ';
		}
	}
	cout << ans << '\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> zkyhelpsme >> T;
	while(T --) solve();
	return 0;
}
//RP ++
//Luogu @zzhengxi
