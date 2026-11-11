#include <bits/stdc++.h>
using namespace std;

void open_file(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

using ll=long long;
constexpr int M=5e5+2,N=502;
int c,n,m,d,q;
int w[M],t[M][N];
ll dis[N][N];
vector<int> g[M];
/* w: 每个地铁站的地铁口走到站厅需要的时间
 * ti,j: 该地铁站 j 的站厅走到第 i 条线路的站台需要的时间
 * disi,j: 线路i -> 线路j of distance
 * gi: 地铁站i的线路
 * than Floyd is ok
 * */

void Floyd(){
	for (int k=1;k<=n;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	open_file("subway");
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;++i)
		cin>>w[i];
	int k,a;
	for (int i=1;i<=n;++i){
		cin>>k;
		while (k--){
			cin>>a;//地铁站a
			g[a].push_back(i);
			cin>>t[i][a];
		}
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			dis[i][j]=1e18;
	for (int i=1;i<=m;++i)
		for (unsigned int j=0;j<g[i].size()-1;++j)
			for (unsigned int k=0;k<g[i].size();++k)
				dis[g[i][j]][g[i][k]]=dis[g[i][k]][g[i][j]]=(ll)t[g[i][j]][i]+t[g[i][k]][i];
	for (int i=1;i<=n;++i) dis[i][i]=0;
	Floyd();
	int x,y;
	ll ans;
	while (q--){
		ans=LONG_LONG_MAX;
		cin>>x>>y;
		for (unsigned int i=0;i<g[x].size();++i)
			for (unsigned int j=0;j<g[y].size();++j)
				ans=min(ans,dis[g[x][i]][g[y][j]]+w[x]+w[y]+t[g[x][i]][x]+t[g[y][j]][y]);
		cout<<ans<<'\n';
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

*/
