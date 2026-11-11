#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int M=5e5+10;
const int N=5e5+510;
const int mod=998244353;
int c,n,m,d,q,cnt,dis[N];
int ww[M];
bool vis[N];
vector<pii>g[N];
void dij(int s){priority_queue<pii>pq;
	pq.push({0,s});
	for(int i=1;i<=m+n;i++)dis[i]=1e18,vis[i]=0;
	dis[s]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first,w=g[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({-dis[v],v});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>ww[i];
	int k,a,w,x,y;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>w;
			g[i+m].push_back({a,w});
			g[a].push_back({i+m,w});
		}
	}
	while(q--){
		cin>>x>>y;
		dij(x);
		cout<<dis[y]+ww[x]+ww[y]<<'\n';
	}
	return 0;
} 
/*
答案为w(xr)+w(yr)+dij(xr->yr)
*/