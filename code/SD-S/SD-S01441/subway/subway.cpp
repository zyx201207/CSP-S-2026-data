#include<bits/stdc++.h>
#define int long long
#define PI pair<int,int>
#define rep(i,a,n) for(int i=a; i<=n; i++)
#define dop(i,a,n) for(int i=n; i>=a; i--)
#define cios cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
using namespace std;
const int N=5e5+10,M=510,INF=0x7f7f7f7f7f7f7f7f;
int c,n,m,d,q,w[N],x,y,k[M],f[M][M],dis[M][M],vis[M][M];
vector<int> a[M],t[M];
vector<PI> b[N];
priority_queue<PI,vector<PI>,greater<PI>>pq;
void dij(int s){
	while(!pq.empty()) pq.pop();
	rep(i,0,n) dis[s][i]=INF;
	dis[s][s]=0;pq.push({0,s});
	while(!pq.empty()){
		int u=pq.top().second;pq.pop();
		if(vis[s][u]) continue;
		vis[s][u]=1;
		for(int i=1; i<=n; i++)
			if(f[u][i]!=INF)
				if(dis[s][i]>dis[s][u]+f[u][i]){
					dis[s][i]=dis[s][u]+f[u][i];
					pq.push({dis[s][i],i});
				}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cios;
	cin>>c>>n>>m>>d>>q;
	rep(i,0,n)rep(j,0,n) f[i][j]=INF;
	rep(i,1,m) cin>>w[i];
	rep(i,1,n){
		cin>>k[i];
		rep(j,1,k[i]){
			cin>>x>>y;
			b[x].push_back({i,y});
		}
	}
	rep(i,1,m)
		for(int j=0; j<b[i].size(); j++)
			for(int k=0; k<b[i].size(); k++){
				int jf=b[i][j].first,js=b[i][j].second;
				int kf=b[i][k].first,ks=b[i][k].second;
				if(j==k){
					f[jf][kf]=0;
					continue;
				}
				f[jf][kf]=min(f[jf][kf],js+ks);
			}
	rep(i,1,n) dij(i);
	while(q--){
		cin>>x>>y;int ans=INF;
		for(int j=0; j<b[x].size(); j++)
			for(int k=0; k<b[y].size(); k++)
				ans=min(ans,dis[b[x][j].first][b[y][k].first]+b[x][j].second+b[y][k].second);
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
