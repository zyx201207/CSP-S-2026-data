#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=510;
long long c[M];
long long dis[N][N];
vector<pair<int,int> > g[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	int C,n,m,d,q;
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
//		cout<<i<<"    ";
		for(int j=1;j<=k;j++){
			int u,t;cin>>u>>t;
			g[u].push_back({i,t});
//			cout<<u<<" ";
		}
//		cout<<"\n";
	}
//	cout<<"\n\n\n";
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
//		cout<<"\n";
//		cout<<i<<"       ";
		for(int j=0;j<g[i].size();j++){
//			cout<<g[i][j].first<<" ";
			for(int k=0;k<j;k++){
				int v=g[i][j].first,w=g[i][j].second;
				int v1=g[i][k].first,w1=g[i][k].second;
				dis[v][v1]=dis[v1][v]=min(dis[v][v1],1ll*w+w1);
			}
		}
	}
//	cout<<"\n\n";
	for(int i=1;i<=n;i++) dis[i][i]=0;
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++) cout<<dis[i][j]<<" ";
//		cout<<"\n";
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int u,v;cin>>u>>v;
		long long as=1e18;
		for(int i=0;i<g[u].size();i++){
			for(int j=0;j<g[v].size();j++){
				int vv=g[u][i].first,w=g[u][i].second;
				int v1=g[v][j].first,w1=g[v][j].second;
//				cout<<vv<<" "<<v1<<"\n";
				as=min(as,dis[vv][v1]+w+w1);
//				cout<<dis[v][v1]<<" "<<w<<" "<<w1<<"***\n";
			}
		}
		cout<<as+c[u]+c[v]<<"\n";
	}
	return 0;
}
/*
可以看作站点与线路连边，跑最短路
边权是走到站台的时间 
边数最多是sigma k的 

注意到，每个地铁站被经过的次数有限，所以圆点连方点边数有限，

n很小，直接暴力 floyd 
*/
