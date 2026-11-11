#include<bits/stdc++.h>
using namespace std;
const int M=5e5+100;
const int N=550; 
int c,n,m,d,q; 
int w[M];
struct edge{
	int v,w;
};
vector<edge>e[M];
long long dis[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int a,t;
			cin>>a>>t;
			e[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i){
		int siz=e[i].size();
		for(int j=0;j<siz-1;++j){
			int u=e[i][j].v,T1=e[i][j].w;
			for(int k=j+1;k<siz;++k){
				int v=e[i][k].v,T2=e[i][k].w;
				//cout<<i<<" "<<u<<" "<<v<<" "<<T1+T2<<"\n";
				dis[u][v]=dis[v][u]=min(dis[u][v],(long long)T1+T2);
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<(int)e[x].size();++j){
			int u=e[x][j].v,T1=e[x][j].w;
			for(int k=0;k<(int)e[y].size();++k){
				int v=e[y][k].v,T2=e[y][k].w;
			//	cout<<"! "<<u<<" "<<v<<"\n";
				//cout<<w[x]<<" "<<T1<<" "<<dis[u][v]<<" "<<T2<<" "<<w[y]<<"\n";
				ans=min(ans,(long long)w[x]+w[y]+T1+T2+dis[u][v]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2



0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
