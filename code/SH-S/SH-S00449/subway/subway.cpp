#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500001];
int cnt[500001];
pair<int,long long>g[500001][21];
long long dis[501][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a;long long t;cin>>a>>t;
			g[a][++cnt[a]]=make_pair(i,t);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1e14;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++){
				int u=g[i][j].first,v=g[i][k].first;
				dis[u][v]=min(dis[u][v],g[i][j].second+g[i][k].second);
				dis[v][u]=dis[u][v];
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
	while(q--){
		int x,y;cin>>x>>y;
		long long ans=1e14;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++){
				ans=min(ans,w[x]+g[x][i].second+dis[g[x][i].first][g[y][j].first]+g[y][j].second+w[y]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

