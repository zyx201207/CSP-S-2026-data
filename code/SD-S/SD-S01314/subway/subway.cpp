#include<bits/stdc++.h>
#define cmin(a,b) a=std::min(a,b)
#define cmax(a,b) a=std::max(a,b)
#define inf ((int)1e18)
#define mod
#define maxn 505
#define maxm 1000006
#define int long long
#define pb push_back
#define pii std::pair<int,int>
#define arr(x) std::array<int,(x)>
#define fi first
#define se second
bool Mst;
int C,n,m,D,q;
int W[maxm];
std::vector<pii> to[maxm];
int dis[maxn][maxn];
void ama10(){
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&D,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&W[i]);
	}
	for(int i=1,k;i<=n;i++){
		scanf("%lld",&k);
		while(k--){
			int x,t;
			scanf("%lld%lld",&x,&t);
			to[x].pb({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		int sz=to[i].size();
		for(int p1=0;p1<sz;p1++){
			int u=to[i][p1].fi,w1=to[i][p1].se;
			for(int p2=p1+1;p2<sz;p2++){
				int v=to[i][p2].fi,w=w1+to[i][p2].se;
				cmin(dis[u][v],w),cmin(dis[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cmin(dis[i][j],dis[i][k]+dis[k][j]); 
			}
		}
	}
	for(int i=1,x,y;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		int ans=inf;
		for(pii e1:to[x]) for(pii e2:to[y]){
			cmin(ans,dis[e1.fi][e2.fi]+e1.se+e2.se);
		}
		printf("%lld\n",ans+W[x]+W[y]);
	}
}
bool Med;
signed main(){
//	fprintf(stderr,"used: %lld MB\n",(&Med-&Mst)/1024/1024);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ama10();
	return 0;
}
/*
-std=c++14 -O2 -lm -Wall -Wl,--stack=1234567890
14:34
T 14:44 \sum k*d+qd^2+n^3
W 14:51
subway.exe < subway1.in > 1.out
subway.exe < subway2.in > 2.out
subway.exe < subway3.in > 3.out
subway.exe < subway4.in > 4.out
subway.exe < subway5.in > 5.out
subway.exe < subway6.in > 6.out
subway.exe < subway7.in > 7.out
fc subway1.ans 1.out
fc subway2.ans 2.out
fc subway3.ans 3.out
fc subway4.ans 4.out
fc subway5.ans 5.out
fc subway6.ans 6.out
fc subway7.ans 7.out
*/


