#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a[550][500050],k[550];
long long w[500050],t[550][200050];
struct s{
	int x,zd,timee;
};
bool vis[550];
vector<s> g[550];
int dfs(int a,int b,int tt){
	if(a==b){
		return tt;
	}
	for(int i=0;i<g[a].size();i++){
		int tx=g[a][i].x;
		if(tx>0&&tx<=n&&!vis[tx]){
			tt+=t[a][g[a][i].zd]+t[tx][g[a][i].zd];
			g[a][i].timee=tt;
			vis[a]=1,vis[tx]=1;
			dfs(tx,b,tt);
		}
	}
}
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j==1){
				continue;
			}
			g[a[i][j]].push_back({a[i][j-1],j,0});
			g[a[i][j-1]].push_back({a[i][j],j,0});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,y,w[x])+w[y];
	}
	
	return 0;
}


