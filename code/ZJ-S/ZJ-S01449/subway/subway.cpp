#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+5;
int c,n,m,d,q,w[N],dis[505][505],D[N];
bool vis[N];
vector<pair<int,int> >ve[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof(dis));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,u=m+i,v,w;
		dis[i][i]=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>v>>w;
			ve[v].push_back({u,w});
		}
	}
	for(int u=1;u<=m;u++){
		for(int i=0;i<ve[u].size();i++){
			for(int j=0;j<ve[u].size();j++){
				dis[ve[u][i].first-m][ve[u][j].first-m]=min(dis[ve[u][i].first-m][ve[u][j].first-m],ve[u][i].second+ve[u][j].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		int ans=LONG_LONG_MAX;
		for(int j=0;j<ve[u].size();j++){
			for(int k=0;k<ve[v].size();k++){
				ans=min(ans,dis[ve[u][j].first-m][ve[v][k].first-m]+ve[u][j].second+ve[v][k].second);
			}
		}cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
