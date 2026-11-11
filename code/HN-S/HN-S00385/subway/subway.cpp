#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int v;
	int w;
};
vector<Edge>edge[505];
vector<Edge>z[500005];
int w[25005],k[505],a[505][100005],t[505][100005];
long long minl=10000000000005;
bool vis[505];
void dfs(int x,int y,long long ans){
	if(x==y){
		minl=min(minl,ans);
		return;
	}
	for(int i=0;i<edge[x].size();i++){
		if(vis[edge[x][i].v]==0){
			vis[edge[x][i].v]=1;
			dfs(edge[x][i].v,y,ans+edge[i][x].w);
			vis[edge[x][i].v]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int maxl=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		maxl=max(maxl,k[i]);
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			z[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<z[i].size();j++){
			for(int k=j+1;k<z[i].size();k++){
				edge[z[i][j].v].push_back({z[i][k].v,z[i][j].w+z[i][k].w});
				edge[z[i][k].v].push_back({z[i][j].v,z[i][j].w+z[i][k].w});
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		minl=10000000000005;
		for(int i=0;i<z[x].size();i++){
			for(int j=0;j<z[y].size();j++){
				dfs(z[x][i].v,z[x][j].v,w[x]+w[y]);
			}
		}
		cout<<minl<<endl;
	}
	return 0;
}

