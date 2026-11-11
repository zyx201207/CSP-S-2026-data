#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=500020,Inf=1e18;
int dis[N][N],tt[M][25],con[M][25],tot[M],w[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q,k,a,t,x,y,ans;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			con[a][++tot[a]]=i,tt[a][tot[a]]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=Inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int l=1;l<=tot[i];l++){
			for(int r=l+1;r<=tot[i];r++){
				int u=con[i][l],v=con[i][r];
				dis[u][v]=min(dis[u][v],tt[i][l]+tt[i][r]);
				dis[v][u]=dis[u][v];
			}
		}
	}
	for(int mid=1;mid<=n;mid++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][mid]+dis[mid][j]);
		}
	}
	while(q--){
		cin>>x>>y;ans=Inf;
		for(int i=1;i<=tot[x];i++){
			for(int j=1;j<=tot[y];j++) 
				ans=min(ans,tt[x][i]+tt[y][j]+dis[con[x][i]][con[y][j]]);
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
//15:21 finish 100pts
//15:25 pass all big samples,1.95s max
//lsy give me luck to get 100pts