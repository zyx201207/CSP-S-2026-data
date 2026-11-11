#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 2e4 + 5;
const int inf = 1e9 + 9;

int c,n,m,d,q;
int w[N];
struct xian{
	int a;
	int t;
};
int G[505][505];
vector<xian> g[N];
vector<xian> GG[N];
int Ans;
int book[N];
void dfs(int u,int v,int sum){
	for(auto x:GG[u]){
		if(!book[x.a]){
			if(x.a==v){
				Ans=min(Ans,sum+x.t);
			}
			book[x.a]=1;
			dfs(x.a,v,sum+x.t);
			book[x.a]=0;
		}
	}
}
void bz1(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			G[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int q=j+1;q<g[i].size();q++){
				int u=g[i][j].a;
				int v=g[i][q].a;
				int uw=g[i][j].t;
				int vw=g[i][q].t;
				G[u][v]=min(G[u][v],uw+vw);
				G[v][u]=min(G[v][u],uw+vw);
				
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			GG[i].push_back({(LL)j,G[i][j]});
			GG[j].push_back({(LL)i,G[i][j]});
			
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	//system("fc a.txt b.txt");

	cin>>c>>n>>m>>d>>q;
	/*
	c	测试点编号
	n	地铁线路数
	m	地铁站数
	d	每个地铁站最多被几条线路经过
	q	计划数。
	*/

	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	
	for(int i=1;i<=n;i++){
		int xx;
		cin>>xx;
		for(int j=1;j<=xx;j++){
			int a,t;
			cin>>a>>t;
			if(!g[a].size()){
				GG[i].push_back({a+505,0});
				GG[a+505].push_back({i,0});
				
			}
			g[a].push_back({i,t});
		}
	}
	bz1();//每条线路之间换乘的min
	
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=w[u]+w[v];
		if(n==1)	cout<<ans<<"\n";
		else{
			for(int i=1;i<=n+m+510;i++){
				book[i]=0;
				
			}
			Ans=inf;
			dfs(u+505,v+505,0);
			cout<<Ans+ans<<"\n";
		}
		
		
	}
	return 0;
}
//
//
/*
0 2 5 20 2
 4 1 9 2 5
3 1 5 2 7 4 6
 3 2 3 3 4 5 7
1 3
 1 2


*/
