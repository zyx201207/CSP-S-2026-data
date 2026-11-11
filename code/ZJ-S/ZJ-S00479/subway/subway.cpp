#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[510000],k,a,t,u,v,ans,num,to[510000];
bool vis[510000];
struct node{
	int ii,w;
};
/*bool cmp(node x,node y){
	return x.w<y.w;
}*/
vector<node> edge[510000];
void dfs(int id){
//	cout<<id<<"  "<<to[id]<<'\n';
	for(int i=0;i<edge[id].size();i++){
		int tt=edge[id][i].ii,ww=edge[id][i].w;
		if(vis[tt]==0){
			vis[tt]=1;
			to[tt]=to[id]+ww;
			dfs(tt);
		}
		else if(to[id]+ww<to[tt]){
			to[tt]=to[id]+ww;
			dfs(tt);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			edge[a].push_back({m+i,t});
			edge[m+i].push_back({a,t});
		}
	}
	for(int i=1;i<=q;i++){
		
		memset(vis,0,sizeof(vis));
		memset(to,0,sizeof(to));
		cin>>u>>v;
		vis[u]=1;
		num=0;
		dfs(u);
		cout<<to[v]+w[u]+w[v]<<'\n';
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
