#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=507,M=150007;
int c,n,m,d,q;
ll w[M],a[N][M],t[N][M];
int to[M][27],tot[M];
int id[N][M];//第i条铁路中站点j的编号 
ll f[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[i][j]=1e18;
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			to[a[i][j]][++tot[a[i][j]]]=i;
			id[i][a[i][j]]=j;
		}
	}
	
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=tot[i];j++){
//			cout<<to[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=tot[i];j++){
			for(int k=j+1;k<=tot[i];k++){
				int u=to[i][j],v=to[i][k];
			//	printf("%d%d\n",u,v);
				f[v][u]=f[u][v]=min(f[u][v],t[u][id[u][i]]+t[v][id[v][i]]);
			}
		}
	}
	//cout<<21321<<"\n";
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)f[i][j]=0;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--){
		ll ans=1e18;
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=tot[x];i++){
			for(int j=1;j<=tot[y];j++){
				int u=to[x][i],v=to[y][j];
				ans=min(ans,w[x]+t[u][id[u][x]]+f[u][v]+t[v][id[v][y]]+w[y]);
				//cout<<i<<" "<<id[i][x]<<" "<<t[i][id[i][x]]<<" "<<j<<" "<<id[j][y]<<" "<<t[j][id[j][y]]<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
