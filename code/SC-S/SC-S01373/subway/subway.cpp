#include <bits/stdc++.h>
using namespace std;
const int maxn=514514;
struct qnode{
	int to,val;
	bool friend operator <(qnode x,qnode y){
		return x.val>y.val;
	}
};
struct node{
	int to,val; 
};
vector<node> vt[maxn];
int dis[maxn];
int dij(int s,int t){
	memset(dis,0x7f,sizeof(dis));
	priority_queue<qnode> q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().to;
		q.pop();
		for(auto k:vt[u]){
			int v=k.to,w=k.val;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return dis[t];
}
int w[maxn],a,t,k,c,n,m,d,q,x,y;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d %d",&a,&t);
			vt[i+m].push_back({a,t});
			vt[a].push_back({i+m,t});
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",dij(x,y)+w[x]+w[y]);
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/