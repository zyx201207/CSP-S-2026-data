#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,T=1;
int n,m;
int d,q;
int w[N];
vector<pair<int,int> >g[N];
int ans;
bool vis[N];
int dis[N];
void dij(int x){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	q.push({0,x});
	dis[x]=0;
	while(!q.empty()){
		auto last=q.top();
		q.pop();
		int u=last.second;
		vis[u]=true;
		for(auto i:g[u]){
			int v=i.first,w=i.second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]){
					q.push({dis[v],v});
				}
			}
		}
	}
}
void solve(){
	cin>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			int u=n+i;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		dij(u);
		cout<<w[u]+w[v]+dis[v]<<"\n";
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in ","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	while(T--){
		solve();
	}
	return 0;
}
