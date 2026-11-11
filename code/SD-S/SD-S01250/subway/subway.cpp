#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10,M=5e3+10,inf=2e18+1;
int c,n,m,d,Q,wei[M],ans[M][M],vis[M];
vector < int > edge[M];
vector < int > w[M]; 
priority_queue < pair < int,int > > q;
void solve(int s){
	for(int i=1;i<=m+n;i++)vis[i]=0;
	ans[s][s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int dis=-q.top().first,u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i],val=w[u][i];
			ans[s][v]=min(ans[s][v],dis+val);
			q.push(make_pair(-ans[s][v],v));
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++)scanf("%lld",&wei[i]);
	for(int i=1;i<=n;i++){
		int k=0;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int p,q;
			scanf("%lld%lld",&p,&q);
			edge[p].push_back(m+i);
			edge[m+i].push_back(p);
			w[p].push_back(q);
			w[m+i].push_back(q);
		}
	}
	for(int i=1;i<=m+n;i++)for(int j=1;j<=m+n;j++)ans[i][j]=inf;
	for(int i=1;i<=m+n;i++){
		solve(i);
	}
	while(Q--){
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",ans[x][y]+wei[x]+wei[y]);
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
8 3 6 1
*/
