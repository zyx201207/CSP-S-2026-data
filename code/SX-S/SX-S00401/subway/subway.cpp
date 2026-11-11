#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e4+10,D=20,N=510;
int w[20],dist[M];
struct node{
	int to,cost;
};
vector<node>Edges[M];
// 应对站台和站厅分别建编号不同的点
// 对于第i个地铁站，令站厅的编号为i，第j个站台的编号为m+(i-1)*d+j
// 则需要建这些边：
// 1. 站台A到站台B
// 2. 站台A到站厅A
// 3. 站台B到站厅B
void spfa(int root,int sum,int pre){
	if(sum>dist[root]) return;
	dist[root]=sum;
	for(auto x:Edges[root]){
		if(x.to!=pre)
			spfa(x.to,sum+x.cost,root);
	}
}
void build(int pre,int to,int cost){
	Edges[pre].push_back({to,cost});
	Edges[to].push_back({pre,cost});
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	int k;
	int alst,anow,tnow;
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			alst=anow;
			scanf("%lld%lld",&anow,&tnow);
			build(anow/*站厅*/,m+(anow-1)*d+i/*站台*/,tnow);
			if(j>=2){
				build(m+(anow-1)*d+i,m+(alst-1)*d+i,0);
			}
		}
	}
	int x,y;
	for(int _=1;_<=q;_++){
		memset(dist,63,sizeof dist);
		scanf("%lld%lld",&x,&y);
		dist[x]=0;
		spfa(x,0,-1);
		cout<<dist[y]+w[x]+w[y]<<endl;
	}
	return 0;
}