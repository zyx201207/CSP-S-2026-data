#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,M=2e4+5;
int c,n,m,d,q,w[M],a[M][M],t[N][M],belong[M][N],cnt[M],k,x,y,p;
long long ans;
vector<int>e[N];
bool vis[N];
void dfs(int u,long long sum,int pos){
	if(u==y){
//		cout<<"\n"<<sum<<"\n";
		ans=min(ans,sum+t[belong[x][p]][x]+t[pos][y]+w[x]+w[y]);
		return ;
	}
	for(int v:e[u]){
		if(vis[v]) continue;
		vis[v]=1;
		for(int i=1;i<=cnt[v];i++){
			dfs(v,sum+((v==y)?0:t[pos][v]+t[belong[v][i]][v]),belong[v][i]);
		}
		vis[v]=0;
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
		cin>>k;
		for(int j=1;j<=k;j++){
			int o;
			cin>>a[i][j]>>o;
			t[i][a[i][j]]=o;
			belong[a[i][j]][++cnt[a[i][j]]]=i;
		}
		for(int u=1;u<=k;u++){
			for(int v=u+1;v<=k;v++){
				e[a[i][u]].push_back(a[i][v]);
				e[a[i][v]].push_back(a[i][u]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		memset(vis,0,sizeof vis);
		ans=1e18;
		vis[x]=1;
		for(p=1;p<=cnt[x];p++){
			dfs(x,0,belong[x][p]);
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
*/

























































































































































































//qwq 
