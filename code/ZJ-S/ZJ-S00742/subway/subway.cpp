#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
#define ll long long 
#define N 1005
#define K 500005
using namespace std;//44pts
int n,m,d,q;
int w[N];
struct node{
	int to;
	int time;
	int road;
	int my;
	node(int a,int b,int c,int d):to(a),time(b),road(c),my(d){}
};
vector<node>G[N];
ll dis[N][N];// i->j dis
int a[K],t[K];
inline void dijkstra(int s){
	for(int i=1;i<=m;i++){
		dis[s][i]=1e18;
	}
	priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>>q;
	dis[s][s]=0;
	q.emplace(0,make_pair(s,0));
	while(!q.empty()){
		int u=q.top().se.fi;
		ll w=q.top().fi;
		int road=q.top().se.se;
		q.pop();
		if(w>dis[s][u])continue;
		for(const node&e:G[u]){
			int v=e.to;
//		printf("%d->%d\n",u,v);
			ll cost=w+e.time;
			if(road!=e.road)cost+=e.my;
//			printf("%d:%lld,%lld\n",s,cost,dis[s][v]);
			if(cost<dis[s][v]){
				dis[s][v]=cost;
				q.emplace(dis[s][v],make_pair(v,e.road));
			}
		}
	}
}
void solve(){
	scanf("%d",&n);
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",w+i);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",a+j,t+j);
		}
		for(int j=1;j<=k;j++){
			for(int p=j+1;p<=k;p++){
				G[a[j]].eb(a[p],t[p],i,t[j]);
				G[a[p]].eb(a[j],t[j],i,t[p]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		printf("%d:",i);
//		for(const node&e:G[i]){
//			printf(" %d",e.to);
//		}
//		puts("");
//	}
	for(int i=1;i<=m;i++){
		dijkstra(i);
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			printf("%20lld%c",dis[i][j],j==m?'\n':' ');
//		}
//	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",dis[x][y]+w[x]+w[y]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
