#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int dis[510][510];
int w[N],k[N],pos[N];
int b[N][25][3];
signed main( ){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			int u,w; cin>>u>>w;
			b[u][pos[u]][0]=i;
			b[u][pos[u]][1]=w;
			pos[u]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=1e18+10;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<pos[i];j++){
			for(int k=j+1;k<pos[i];k++){
				int val=b[i][j][1]+b[i][k][1];
				int u=b[i][j][0],v=b[i][k][0];
				dis[u][v]=min(dis[u][v],val);
				dis[v][u]=min(dis[v][u],val);
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
		int x,y; cin>>x>>y;
		int minn=1e18+10;
		for(int i=0;i<pos[x];i++){
			for(int j=0;j<pos[y];j++){
				minn=min(minn,dis[b[x][i][0]][b[y][j][0]]+b[x][i][1]+b[y][j][1]);
			}
		} 
		cout<<minn+w[x]+w[y]<<endl;
	}
	return 0;
} 
