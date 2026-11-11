#include<bits/stdc++.h>
#define int long long
#define PII pair<int,pair<int,int>>
using namespace std;
const int N=1e3+5;
int c,n,m,d,q,x,y,ans;
int k[N],a[N][N],t[N][N];
int w[N],vis[N],b[N];
int dis[N][N];
vector<pair<int,int>> g[N];

void dijkstra(int s){
	priority_queue<PII,vector<PII>,greater<PII>> q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(b,0,sizeof b);
	dis[s][0]=0;
	q.push({0,{s,0}});
	while(q.size()){
		int u=q.top().second.first;
		int uw=q.top().second.second;q.pop();
		for(auto p:g[u]){
			int v=p.first,vw=p.second;
			if(vw!=uw){
				if(dis[v][vw]>dis[u][uw]+t[uw][u]+t[vw][u]){
					dis[v][vw]=dis[u][uw]+t[uw][u]+t[vw][u];
					b[v]=vw;
					q.push({dis[v][vw],{v,vw}});
				}
			}
			else{
				if(dis[v][vw]>dis[u][uw]){
					dis[v][vw]=dis[u][uw];
					b[v]=vw;
					q.push({dis[v][vw],{v,vw}});
				}
			}
		}
	}
}

signed main(){
	freopen("subway3.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			if(j>1){
				g[a[i][j-1]].push_back({a[i][j],i});
				g[a[i][j]].push_back({a[i][j-1],i});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		dijkstra(x);
		ans=1e18;
		for(int i=1;i<=n;i++){
			if(dis[y][i]>1e9) continue;
			ans=min(ans,dis[y][i]);
		}
		ans=ans+w[x]+w[y]+t[b[y]][y];
		cout<<ans<<"\n";
	}
	return 0;
}
