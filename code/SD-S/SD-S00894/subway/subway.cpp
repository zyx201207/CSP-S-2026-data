#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
const int N=1e7+10;
const long long INF=1e18;
struct node{
	long long nxt,to,val;
}e[N];
int d,q1,c,n,m;
long long vis[M],w[M],k[510],cnt,h[M],a[M],t[M],dis[M];
void lsqxxing(long long u,long long v,long long w){
	e[++cnt].to=v;
	e[cnt].val=w;
	e[cnt].nxt=h[u];
	h[u]=cnt;
}
void dijkstra(long long st,long long en){
	dis[0]=INF;
	for(int i=1;i<=m;i++){
		dis[i]=INF;
		vis[i]=0;
	}
	dis[st]=0;
	while(1){
		int u=0;
		for(int i=1;i<=m;i++)
			if(!vis[i]&&dis[i]<dis[u])
				u=i;
		vis[u]=1;
		if(u==0||u==en)break;
		for(int i=h[u];i;i=e[i].nxt){
			if(dis[e[i].to]>dis[u]+e[i].val){
				dis[e[i].to]=dis[u]+e[i].val;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q1);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%lld%lld",&a[j],&t[j]);
		if(c>=7&&c<=11){
			lsqxxing(a[1],a[2],t[1]+t[2]);
			lsqxxing(a[2],a[1],t[1]+t[2]);
		}
		for(int j=1;j<=k[i];j++){
			for(int l=1;l<=k[i];l++){
				if(l!=j)
					lsqxxing(a[j],a[l],t[j]+t[l]);
			}
		}
	}
	while(q1--){
		long long x,y;
		scanf("%lld%lld",&x,&y);
		dijkstra(x,y);
		printf("%lld\n",dis[y]+w[x]+w[y]);
	}
	return 0;
}
