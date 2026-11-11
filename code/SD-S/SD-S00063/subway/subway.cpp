#include<bits/stdc++.h>
using namespace std;
const int N=520,M=5e5+10;
const long long inf=1e18;
long long c,n,m,d,q,dis[N][N],w[M],di[M][21],k[N],a[N][N],t[N][N],u,v,mi,lii;
vector <pair<int,long long>> e[M];//表示第i个站有多少条线{i,t[i][j]}表示有i且到i站台为t[i][j]的时间 
//dis为地铁站之间的距离，查询时查询uv所在线路的最短dis.
//不同地铁站间可以用点链接 

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=0;i<=n+10;i++){
		for(int j=0;j<=n+10;j++)dis[i][j]=inf;
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			e[a[i][j]].push_back({i,t[i][j]});//第ij号车站有第i条线
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int kk=j+1;kk<e[i].size();kk++){
				dis[e[i][j].first][e[i][kk].first]=dis[e[i][kk].first][e[i][j].first]=min(dis[e[i][j].first][e[i][kk].first],e[i][j].second+e[i][kk].second);
			}
		}
	}
	for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				dis[i][k]=dis[k][i]=min(dis[i][k],dis[i][j]+dis[j][k]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
//		cout<<"\n";
//	}
	while(q--){
		cin>>u>>v;
		mi=inf;
		for(int i=0;i<e[u].size();i++){
			for(int j=0;j<e[v].size();j++){
//				if(mi>dis[e[u][i].first][e[v][j].first]+e[u][i].second+e[v][j].second)cout<<dis[e[u][i].first][e[v][j].first]+e[u][i].second+e[v][j].second<<"\n";
				mi=min(mi,dis[e[u][i].first][e[v][j].first]+e[u][i].second+e[v][j].second);
			}
		}
		cout<<w[u]+w[v]+mi<<"\n";
	}
	return 0;
}
