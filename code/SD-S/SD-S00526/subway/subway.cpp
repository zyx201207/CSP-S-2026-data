#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
#define piii pair<int,pair<int,int>>
#define For(a,b,c) for(int i=a;i<=b;i+=c)
#define rep(a,b,c) for(int i=a;i>=b;i-=c)
const int M=5e5+5, N=505; 
ll c, n, m, d, q;
ll w[M], k, a[M], t; 
struct edge{int v, line;};
vector<vector<edge>> g;
vector<ll> dis;
ll tim[N][N];
ll by[N];
void dijk(int s, int ln){
	dis[s]=0ll;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({s,ln});
	while(pq.size()){
		auto a=pq.top();
		int u=a.first, lin=a.second;
		pq.pop();
		for(auto e:g[u]){
			int v=e.v, line=e.line;
			int x=(lin==line ? 0:tim[u][lin]+tim[u][line]);
			//cout << v << ' ' << u << '\n';
			//cout << dis[v] << ' ' << dis[u] << ' ' << x << '\n';
			//cout << (dis[v]>dis[u]+x) << '\n';
			if(dis[v]>dis[u]+x){
				dis[v]=dis[u]+x;
				//cout << dis[v] << '\n';
				by[v]=line;
				pq.push({v,line});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	g.resize(m+1);
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[j] >> t;
			tim[a[j]][i]=t;
			if(j!=1) {
				g[a[j]].push_back({a[j-1],i});
				g[a[j-1]].push_back({a[j],i});
			}
		}
	}
	while(q--){
		ll x, y;
		cin >> x >> y;
		dis.resize(m+1,1e18);
		dijk(x,0);
		//for(int i=1;i<=m;i++) cout << dis[i] << ' ';
		//cout << '\n'; 
		cout << dis[y]+w[x]+w[y]+tim[y][by[y]] << '\n';
	}
	return 0;
}
