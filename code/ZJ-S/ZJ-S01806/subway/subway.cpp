#include<bits/stdc++.h>
using namespace std;
#define int long long

int T[500010];
vector<int>g[500010],gw[500010];
int dis[510][510];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	int P,n,m,d,q;
	cin>>P>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>T[i];
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			g[v].push_back(i);
			gw[v].push_back(t);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				int u=g[i][j],v=g[i][k];
				dis[u][v]=dis[v][u]=min(dis[u][v],gw[i][j]+gw[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j || i==k || j==k) continue;
				if(dis[i][j]>dis[i][k]+dis[k][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
				}
			}
		}
	}
	for(int t=1;t<=q;t++){
		int s,e;
		cin>>s>>e;
		int ans=1e18;
		for(int i=0;i<g[s].size();i++){
			for(int j=0;j<g[e].size();j++){
				int u=g[s][i],v=g[e][j];
				ans=min(ans,gw[s][i]+gw[e][j]+dis[u][v]);
			}
		}
		ans+=T[s]+T[e];
		printf("%lld\n",ans);
	}
	return 0;
}

