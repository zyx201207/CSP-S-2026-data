#include<bits/stdc++.h>
#define rep(i,a,b) for(long long i=(a);i<=(b);++i)
#define debug(a) cout<<#a<<"="<<a<<"\n";
using namespace std;
const long long N=5e5+7,M=5e2+7;
long long b[M][M],ans;
int n,m,q,a[N];
struct node{
	long long to,w;
};
vector<node> g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int id,d;
	scanf("%d%d%d%d%d",&id,&m,&n,&d,&q);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,m){
		int x;
		scanf("%d",&x);
		rep(j,1,x){
			int y,z;
			scanf("%d%d",&y,&z);
			g[y].push_back({i,z});
		}
	}
	rep(i,1,m){
		rep(j,1,m) b[i][j]=1e18;
		b[i][i]=0;
	} 
	rep(i,1,n){
		for(int j=0;j<g[i].size();++j){
			int u=g[i][j].to;
			for(int k=j+1;k<g[i].size();++k){
				int v=g[i][k].to;
				b[u][v]=b[v][u]=min(b[u][v],g[i][j].w+g[i][k].w);
			}
		}
	}
	rep(k,1,m){
		rep(i,1,m){
			rep(j,1,m){
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
			}
		}
	}
	rep(i,1,q){
		int u,v;
		scanf("%d%d",&u,&v);
		ans=1e18;
		for(int j=0;j<g[u].size();++j){
			int x=g[u][j].to;
			for(int k=0;k<g[v].size();++k){
				int y=g[v][k].to;
				ans=min(ans,a[u]+a[v]+b[x][y]+g[u][j].w+g[v][k].w);
			}
		}
		printf("%lld\n",ans);
	}
    return 0;
}
