#include <bits/stdc++.h>
using namespace std;
const int inf=0x7f7fffff,N=500010;
struct edge{
	int v,w;
};
int m,n,c,d,q,w[N],k,a,t,x,y;
vector<edge> e[555+N];
long long dis[555][555],temp[N];
queue<int> nxt;
void dijkstra(int s){
	for(int j=1;j<=n;j++){
		temp[j]=inf;
	}
	dis[s][s]=0;
	nxt.push(s);
	while(!nxt.empty()){
		int u=nxt.front();
		nxt.pop();
		for(auto ed : e[u]){
			int v=ed.v,we=ed.w;
			if(u<555){
				if(e[v].size()>1 && temp[v-555]>dis[s][u]+we){temp[v-555]=dis[s][u]+we,nxt.push(v);}
//				printf("%d u:%d v:%d %d\n",e[v].size(),u,v,dis[s][u]+we);
			}else{
				if(dis[s][v]>temp[u-555]+we)dis[s][v]=temp[u-555]+we,nxt.push(v);
			}
		}
	}
}
long long getans(int x,int y){
	long long gans=inf;
//	cout<<x+555;
	for(auto ed : e[x+555]){
		int vx=ed.v,wx=ed.w;
		for(auto eg : e[y+555]){
			int vy=eg.v,wy=eg.w;
//			cout<<wx+wy+dis[vx][vy];
			gans=min(gans,wx+wy+dis[vx][vy]);
		}
	}gans+=(w[x]+w[y]);
	return gans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1,t;j<=k;j++){
			scanf("%d%d",&a,&t);
			e[i].push_back({a+555,t});
			e[a+555].push_back({i,t});
		}
	}for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	for(int r=1;r<=q;r++){
		scanf("%d%d",&x,&y);
//		printf("%d %d ",x,y);
		printf("%lld\n",getans(x,y));
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			printf("%lld ",dis[i][j]);
//		}printf("\n");
//	}
}