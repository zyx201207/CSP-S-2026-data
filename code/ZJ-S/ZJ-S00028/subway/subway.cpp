#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+505;
const ll inf=5e14+5;
int c,n,m,D,Q,w[N];
bool vis[N];
ll d[N],ans[N];
struct node{
	int v;ll w;
	bool operator<(const node &ot)const{return w>ot.w;}
};priority_queue<node> q;
vector<node> e[N],qry[N];
void dij(int s){
	for(int i=1;i<=n+m;i++) d[i]=inf,vis[i]=0;
	d[s]=0;q.push({s,0});
	while(!q.empty()){
		int u=q.top().v; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(node to:e[u])
		if(!vis[to.v] && d[u]+to.w<d[to.v]){
			d[to.v]=d[u]+to.w;
			q.push({to.v,d[to.v]});
		}
	}
}
namespace n_2{
	ll tim[3][N];
	void main(){
		for(int i=1;i<=m;i++)
			tim[1][i]=tim[2][i]=inf;
		for(int i=1;i<=n;i++){
			int s,v,t;
			scanf("%d",&s);
			for(int j=1;j<=s;j++){
				scanf("%d%d",&v,&t);
				tim[i][v]=min(tim[i][v],(ll)t);
			}
		}
		ll t=inf;int x,y;
		for(int i=1;i<=m;i++)
			t=min(t,tim[1][i]+tim[2][i]);
		while(Q--){
			scanf("%d%d",&x,&y);
			printf("%lld\n",w[x]+w[y]+min( min(tim[1][x]+tim[2][y]+t,tim[1][y]+tim[2][x]+t),
			min(tim[1][x]+tim[1][y],tim[2][x]+tim[2][y]) ));
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	if(n<=2){n_2::main();return 0;}
	for(int i=1;i<=n;i++){
		int s,v,t;
		scanf("%d",&s);
		for(int j=1;j<=s;j++){
			scanf("%d%d",&v,&t);
			e[m+i].push_back({v,t});
			e[v].push_back({m+i,t});
		}
	}
	for(int i=1,x,y;i<=Q;i++){
		scanf("%d%d",&x,&y);
		if(y<x) swap(x,y);
		qry[x].push_back({y,i});
	}
	for(int xx=1;xx<=m;xx++)
	if(qry[xx].size()){
		dij(xx);
		for(node t:qry[xx])
			ans[t.w]=d[t.v]+w[xx]+w[t.v];
	}
	for(int i=1;i<=Q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}
