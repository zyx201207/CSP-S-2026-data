#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 1e6 + 5;
const ll M = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
struct edge{
	ll v,w;
};
struct Query{
	int v,id;
};
struct node{
	ll x,d;
	bool operator < (const node &e) const{
		return d > e.d;
	}
};
int test_id,n,n1,m,d,q,a[N];
ll dis[N],ans[N];
bool vis[N]; 
vector<edge> E[N];
vector<Query> g[N];
void dijkstra(int s){
	for(int i = 1;i <= n1;i++){
		dis[i] = INF,vis[i] = 0;
	}
	priority_queue<node> q;
	q.push({s,0});
	dis[s] = 0;
	while(!q.empty()){
		int u = q.top().x,d = q.top().d;
		q.pop();
		if(d > dis[u]) continue;
		if(vis[u]) continue;
		vis[u] = 1;
		for(auto e : E[u]){
			int v = e.v,w = e.w;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				if(vis[v] == 0){
					q.push({v,dis[v]});
				}
			}
		}
	}
	for(auto e : g[s]){
		int v = e.v,id = e.id;
		ans[id] = a[s] + dis[v] + a[v];
	}
}
void work(){
	cin >> test_id >> m >> n >> d >> q;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	n1 = n;
	for(int i = 1;i <= m;i++){
		int k;
		cin >> k;
		n1++;
		a[n] = 0;
		for(int j = 1;j <= k;j++){
			int x,t;
			cin >> x >> t;
			E[x].push_back({n1,t});
			E[n1].push_back({x,t});
		}
	}
	for(int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
		g[x].push_back({y,i});
	}
	for(int i = 1;i <= n;i++){
		if((int)g[i].size() == 0) continue;
		dijkstra(i);
	}
	for(int i = 1;i <= q;i++){
		cout << ans[i] << "\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int oT_To = 1;
	//cin >> oT_To;
	while(oT_To--){ work();}
	return 0;
}

