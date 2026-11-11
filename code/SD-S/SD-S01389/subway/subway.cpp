#include<bits/stdc++.h>
//#define INF 1e11+1
using namespace std;
const int maxm=5e5+5;
int c,n,m,dd,q;
int len[610],op[maxm];
int d[610][maxm];
struct node{
	int xl,zl;
};
vector<node>G[maxm];
int ans=1e11+1,sum,w[maxm];
bool vis[maxm];
void dfs(int qd,int zd,int pas){
//	cout<<qd<<'\n';
	if (qd==zd){
		sum+=d[pas][zd];
		ans=min(ans,sum);return ;
	}
	for (int i=0;i<G[qd].size();i++){
		if (!vis[G[qd][i].xl]){
			if (pas==0){
				sum+=d[G[qd][i].zl][qd];
				vis[G[qd][i].xl]=1;
				dfs(G[qd][i].xl,zd,G[qd][i].zl);
				vis[G[qd][i].xl]=0;
				sum-=d[G[qd][i].zl][qd];
			} 
			else if (G[qd][i].zl==pas){
				vis[G[qd][i].xl]=1;
				dfs(G[qd][i].xl,zd,pas);
				vis[G[qd][i].xl]=0;
			}
			else {
				sum+=d[pas][qd];
				sum+=d[G[qd][i].zl][qd];
				vis[G[qd][i].xl]=1;
				dfs(G[qd][i].xl,zd,G[qd][i].zl);
				vis[G[qd][i].xl]=0;
				sum-=d[pas][qd];
				sum-=d[G[qd][i].zl][qd];
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	cin>>c>>n>>m>>dd>>q;
	for (int i=1;i<=m;i++){
		cin>>w[i];
	}
	for (int i=1;i<=n;i++){
		cin>>len[i];
		for (int j=1;j<=len[i];j++){
			int y;
			cin>>op[j]>>y;
			d[i][op[j]]=y;
			if (j==1) continue;
			G[op[j-1]].push_back({op[j],i});
			//G[op[j]].push_back({op[j-1],i});
		}
	}
	while (q--){
		int u,v;sum=0;
		cin>>u>>v;sum+=w[u];sum+=w[v];
		/*for (int i=1;i<=n;i++){
			sum+=d[i][u];
			dfs(u,v,G[u][i].zl);
			sum-=d[i][u];
		}*/
		vis[u]=1;
		dfs(u,v,0);
		for (int i=1;i<=m;i++) vis[i]=0;
		cout<<ans<<'\n';ans=1e11+1;
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
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
