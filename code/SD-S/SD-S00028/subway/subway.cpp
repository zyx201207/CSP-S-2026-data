#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q,w[M],f[N][N];
vector<pair<int,int>>g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q,memset(f,0x3f,sizeof(f));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,u,c;
		cin>>k,f[i][i]=0;
		while(k--){
			cin>>u>>c;
			g[u].emplace_back(i,c);
		}
	}
	for(int i=1;i<=m;i++){
		for(int x=0;x<(int)g[i].size();x++)
			for(int y=0;y<(int)g[i].size();y++)
				f[g[i][x].first][g[i][y].first]=min(f[g[i][x].first][g[i][y].first],g[i][x].second+g[i][y].second);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		int u,v,ans=1e18;
		cin>>u>>v;
		for(int x=0;x<(int)g[u].size();x++)
			for(int y=0;y<(int)g[v].size();y++)
				ans=min(ans,g[u][x].second+g[v][y].second+f[g[u][x].first][g[v][y].first]);
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
