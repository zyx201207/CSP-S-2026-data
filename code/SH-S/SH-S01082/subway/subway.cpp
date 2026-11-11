#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=509,M=5e5+10;
const ll INF=1e18+10;
ll C,n,m,d,q;
ll w[M];
ll k[N];
struct edge{
	int to,nxt,w;
}e[M*40];
int hd[M+N],nE;
void add(int u,int v,int w){
	e[++nE]=(edge){v,hd[u],w};
	hd[u]=nE;
}
ll c[N][N];
void pre_lk_c(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) c[i][j]=0;
			else c[i][j]=INF;
		}
	}
	for(int u=N+1;u<=N+m;u++){
		for(int i=hd[u];i;i=e[i].nxt){
			for(int j=e[i].nxt;j;j=e[j].nxt){
				if(!j) break;
				int vi=e[i].to,vj=e[j].to;
				ll wi=e[i].w,wj=e[j].w;
				c[vi][vj]=min(c[vi][vj],wi+wj);
				c[vj][vi]=min(c[vj][vi],wi+wj);
			}
		}
	}
}
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<c[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
}
void prework(){
	pre_lk_c();
	Floyd();
}
ll solve(int x,int y){
	ll ans=INF;
	for(int i=hd[x];i;i=e[i].nxt){
		for(int j=hd[y];j;j=e[j].nxt){
			int u=e[i].to,v=e[j].to;
			ll t=e[i].w+e[j].w+c[u][v];
			ans=min(ans,t);
		}
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
		scanf("%lld",k+i);
		for(int j=1;j<=k[i];j++){
			int a,t;
			scanf("%d%d",&a,&t);
			add(i,N+a,t);
			add(N+a,i,t);
		}
	}
	prework();
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=w[x]+w[y]+solve(N+x,N+y);
		printf("%lld\n",ans);
	}
	return 0;
}

