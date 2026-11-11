#include<bits/stdc++.h> 
using namespace std;
#define mk make_pair
#define pli pair<long long,int>
#define pii pair<int,int>

typedef long long ll;
const int N=505;
const int M=2e4+10;
int c,n,m,d,qq;
vector<pli > g[M+N];
ll w[M];
int k[N];
priority_queue<pli ,vector<pli>,greater<pli> > q;
//ll f[M+N][M+N];
//m+i:第i个地铁站超级源  
ll dis[N+M];
vector<ll> ans[N+M];

void dij(int s){
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push(mk(dis[s],s));
	while(!q.empty()){
		pli cur=q.top();q.pop();
		int u=cur.second;
		for(pli tmp:g[u]){
			int v=tmp.second,w=tmp.first;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(mk(dis[v],v));
			}
		}
	}
	
	return;
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qq);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
//	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int a;
			ll t;
			scanf("%d%lld",&a,&t);
			g[m+i].push_back(mk(t,a));
			g[a].push_back(mk(t,m+i));
//			f[a][m+i]=f[m+i][a]=t;
		}
	}
	for(int i=1;i<=m;i++){
		dij(i);
		for(int j=1;j<=m;j++)
		  ans[i].push_back(dis[j]);
//		for(int j=1;j<=m;j++)printf("%lld ",ans[i][j]);
//		printf("\n");
	}
	
//	for(int k=1;k<=m+n;k++)
//	  for(int i=1;i<=m+n;i++)
//	    for(int j=1;j<=n+m;j++)
//	      if(f[i][k]+f[k][j]<=f[i][j])
//	        f[i][j]=f[i][k]+f[k][j];
//	printf("?\n");
	for(int i=1;i<=qq;i++){
//		scanf("%d%d",&x[i],&y[i]);
		int x,y;
		scanf("%d%d",&x,&y);
//		printf("%d %d\n",x,y);
		ll val=w[x]+w[y]+ans[x][y-1];
		printf("%lld\n",val);
	}
	return 0;
}
