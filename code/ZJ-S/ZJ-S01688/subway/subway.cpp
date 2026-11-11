#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510,M=5e5+10,inf=1e18;
int dis[N][N],cnt[M],t[M][25],k[N],w[M],c,n,m,d,q;
int mp2[M][25];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//  O(m*d*d+q*d*d)
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>x>>t[x][++cnt[x]];
			mp2[x][cnt[x]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=1;k<=cnt[i];k++){
				if(j==k)continue;
				int u=mp2[i][j];
				int v=mp2[i][k];
				dis[u][v]=min(dis[u][v],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(k==i)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		int ans=inf;
		for(int j=1;j<=cnt[u];j++){
			for(int k=1;k<=cnt[v];k++){
				int _u=mp2[u][j],_v=mp2[v][k];
				ans=min(ans,w[u]+w[v]+t[u][j]+t[v][k]+dis[_v][_u]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
