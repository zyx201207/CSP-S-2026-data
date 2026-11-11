//张芃浩 西安交通大学附属中学 SN-S00346 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mx=1e18;
int c,n,m,d,q;
int w[500005];
int to[500005][25],pw[500001][25],cnt[500005];
int dis[505][505];
void chkmin(int &x,int y){
	if(y<x)x=y;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,u,w;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>w;
			cnt[u]++,to[u][cnt[u]]=i,pw[u][cnt[u]]=w;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dis[i][j]=mx;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++)
			for(int k=1;k<=cnt[i];k++)
				chkmin(dis[to[i][j]][to[i][k]],pw[i][j]+pw[i][k]),chkmin(dis[to[i][k]][to[i][j]],pw[i][j]+pw[i][k]);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				chkmin(dis[i][j],dis[i][k]+dis[k][j]);
	}
	for(int i=1;i<=q;i++){
		int x,y,ans=mx;
		cin>>x>>y;
		for(int j=1;j<=cnt[x];j++)for(int k=1;k<=cnt[y];k++)chkmin(ans,dis[to[x][j]][to[y][k]]+pw[x][j]+pw[y][k]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
