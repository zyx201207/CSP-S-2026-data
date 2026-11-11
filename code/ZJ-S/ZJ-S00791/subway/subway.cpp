#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mx=5e5+5;
int c,n,m,o[mx],d,q,mp[505][505],dp[505][505];
struct edge{
	int z,t;
};
vector<edge> a[505],b[mx];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>o[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,ti;
			cin>>u>>ti;
			a[i].push_back({u,ti});
			b[u].push_back({i,ti});
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mp[i][j]=1e18;
	for(int i=1;i<=n;i++)mp[i][i]=0;
	for(int i=1;i<=m;i++){
		if(b[i].size()<=1)continue;
		for(int j=0;j<b[i].size();j++){
			int u=b[i][j].z,t=b[i][j].t;
			for(int k=0;k<b[i].size();k++){
				int v=b[i][k].z;
				if(v!=u)mp[u][v]=min(mp[u][v],t+b[i][k].t);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=0;i<b[x].size();i++){ 
			int u=b[x][i].z,t=b[x][i].t; 
			for(int j=0;j<b[y].size();j++){
				int v=b[y][j].z;
				ans=min(ans,b[y][j].t+t+mp[u][v]); 
			}
		} 
		cout<<ans+o[x]+o[y]<<"\n";
	}
	return 0;
}
