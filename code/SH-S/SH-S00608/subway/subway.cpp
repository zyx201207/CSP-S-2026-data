#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
const int M=500005;
const int D=25;
const int N=505;
int w[M],k[N];
vector<pair<int,int> > a[M];//经过线路,站台到站厅距离 
int dis[N][N];
const int INF=(1e13);
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			} 
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int u,v;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>u>>v;
			a[u].push_back(make_pair(i,v));
		}
	}
	int t1,t2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=INF;
		dis[i][i]=0; 
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			u=a[i][j].first;
			t1=a[i][j].second;
			for(int l=j+1;l<a[i].size();l++){
				v=a[i][l].first;
				t2=a[i][l].second;
				dis[u][v]=min(dis[u][v],t1+t2);
				dis[v][u]=min(dis[v][u],t1+t2);
			}
		}
	}
	floyd();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<"->"<<j<<":"<<dis[i][j]<<"\n";
//		}
//	}
	int x,y,ans;
	while(q--){
		cin>>x>>y;
		ans=INF;
		for(int j=0;j<a[x].size();j++){
			for(int k=0;k<a[y].size();k++){
				ans=min(ans,w[x]+w[y]+a[x][j].second+a[y][k].second+dis[a[x][j].first][a[y][k].first]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
