#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k[N];
long long g[N][N];
vector<pair<int,int> > e[M];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(i!=j)g[i][j]=1e18;
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int v,val;
			cin>>v>>val;
			e[v].push_back({i,val});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<e[i].size();j++){
			for(int k=j+1;k<e[i].size();k++){
				int u=e[i][j].first,v=e[i][k].first;
				long long val=e[i][j].second+e[i][k].second;
				g[u][v]=min(g[u][v],val);
				g[v][u]=min(g[v][u],val);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long res=1e18;
		for(pair<int,int> xx:e[x]){
			for(pair<int,int> yy:e[y]){
				res=min(res,g[xx.first][yy.first] + xx.second + yy.second + w[x] + w[y]);
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}
