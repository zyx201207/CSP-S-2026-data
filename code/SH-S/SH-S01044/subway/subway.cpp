#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e2+10,M=5e5+10,inf=2e18;
void optimize(){
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL); 
}
int c,n,m,d,q,dis[N][N],w[M],a[M][21],cnt[M];//dis 表示线路距离 w表示点权 a表示 
vector<int> g[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	optimize();
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			a[x][cnt[x]]=y;
			//cout<<"?"<<a[x][cnt[x]]<<"\n";
			cnt[x]++;
			g[x].push_back(i); 
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			int u=g[i][j];
			for(int k=0;k<g[i].size();k++) {
				int v=g[i][k];
				if(v==u) dis[u][v]=dis[v][u]=0;
				else dis[u][v]=dis[v][u]=min(dis[u][v],a[i][j]+a[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) {
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				//cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
			}
		}
	}
	for(int i=1,u,v;i<=q;i++){
		cin>>u>>v;
		int ans=inf;
		for(int j=0;j<g[u].size();j++){
			for(int k=0;k<g[v].size();k++){
				int x=g[u][j],y=g[v][k];
				ans=min(dis[x][y]+a[u][j]+a[v][k],ans);
			}
		}
		ans+=w[u]+w[v];
		cout<<ans<<"\n";
	}
	return 0;
}
