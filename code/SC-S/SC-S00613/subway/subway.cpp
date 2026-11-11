#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=2e4+5,MM=5e5+5;
int c,n,m,d,q,w[MM],k[N],a[N][M],t[N][M],dis[N][N],cnt[MM];
vector<pair<int,int> > cntstas[M];
vector<int> stations[MM];

void solve1(){
	int T;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int aa,tt;
			cin>>aa>>tt;
			T=tt;
			stations[aa].push_back(i);
			cnt[aa]++;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		if(stations[i].size()>=2){
			for(int x=0;x<cnt[i];x++){
				int u=stations[i][x];
				for(int y=x+1;y<cnt[i];y++){
					int v=stations[i][y];
					dis[u][v]=dis[v][u]=2;
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=0;i<cnt[x];i++){
			int u=stations[x][i];
			for(int j=0;j<cnt[y];j++){
				int v=stations[y][j];
				if(dis[u][v]<0x3f3f3f3f3f3f3f3f)
					ans=min(ans,T+T+dis[u][v]*T);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	if(c>=16 && c<=19){
		solve1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cntstas[a[i][j]].push_back({i,j}); //a[i][j]站点有第i条线路，是这个线路的第j站 
			cnt[a[i][j]]++;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++){
		if(cntstas[i].size()>=2){
			for(int x=0;x<cnt[i];x++){
				int u=cntstas[i][x].first,wx=cntstas[i][x].second;
				for(int y=x+1;y<cnt[i];y++){
					int uu=cntstas[i][y].first,wy=cntstas[i][y].second;
					dis[u][uu]=min(dis[u][uu],t[u][wx]+t[uu][wy]);
					dis[uu][u]=min(dis[uu][u],t[u][wx]+t[uu][wy]);
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(int i=0;i<cnt[x];i++){
			int u=cntstas[x][i].first,wi=cntstas[x][i].second;
			for(int j=0;j<cnt[y];j++){
				int v=cntstas[y][j].first,wj=cntstas[y][j].second;
				if(dis[u][v]<0x3f3f3f3f3f3f3f3f)
					ans=min(ans,t[u][wi]+t[v][wj]+dis[u][v]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}