#include<bits/stdc++.h>
using namespace std;
const int N=505;
long long c,n,m,d,q,w[N],k[N],u,st,ed,dis[N],cost,t[N][N],a[N][N],s=0;
vector <long long> g[N];
void dfs(int x,int ed) {
	if(x==ed&&s==0) {
		printf("%lld\n",cost);
		s=1;
		return ;
	}
	for(int i=0; i<g[x].size(); i++) {
		if(dis[g[x][i]]==0) {
			dis[g[x][i]]=1;
			cost+=t[x][g[x][i]]+t[x][x];
			dfs(g[x][i],ed);
			dis[g[x][i]]=0;
			cost-=t[x][g[x][i]]+t[x][x];
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld",&c);
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&d);
	scanf("%lld",&q);
	long long t[n+2][n+2]= {0};
	for(long long i=1; i<=m; i++) {
		scanf("%lld",&w[i]);
	}
	for(long long i=1; i<=n; i++) {
		scanf("%lld",&k[i]);
		for(long long j=1; j<=k[i]; j++) {
			scanf("%lld",&a[i][j]);
			scanf("%lld",&t[i][j]);
		}
		for(long long j=1;j<=k[i];j++){
			for(long long jj=1;jj<=k[i];jj++){
				if(j!=jj){
					g[j].push_back(jj);
					g[jj].push_back(j);
				}
			}
		}
	}
	while(q--){
		scanf("%lld",&st);
		scanf("%lld",&ed);
		cost=w[st]+w[ed],s=0;
		dfs(st,ed);
	}
	return 0;
}

