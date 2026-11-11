#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e2+5,M=5e5+5;
vector<pii > G[M];
int n,m,c,d,q,dis[N][N],w[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,t,a;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			G[a].push_back({i,t});
		}
	}
	memset(dis,63,sizeof(dis));
	for(int i=1;i<=m;i++){
		for(int j=0;j<G[i].size();j++){
			for(int k=j+1;k<G[i].size();k++){
				int u=G[i][j].fi,v=G[i][k].fi,wu=G[i][j].se,wv=G[i][k].se;
				dis[u][v]=min(dis[u][v],wu+wv);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
	}
	for(int k=2;k<=n;k++){
		for(int i=1;i<k;i++){
			for(int j=i+1;j<k;j++){
				dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
			}
		}
		for(int i=1;i<k;i++){
			for(int j=i+1;j<=k;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	while(q--){
		int st,en,ans=LONG_LONG_MAX;
		cin>>st>>en;
		if(st==en){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<G[st].size();i++){
			for(int j=0;j<G[en].size();j++){
				int u=G[st][i].fi,v=G[en][j].fi,wu=G[st][i].se,wv=G[en][j].se;
				ans=min(ans,dis[u][v]+wu+wv);
			}
		}
		cout<<ans+w[st]+w[en]<<"\n";
	}
	return 0;
}