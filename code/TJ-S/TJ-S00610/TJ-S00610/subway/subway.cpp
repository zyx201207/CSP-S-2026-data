#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
template <typename T>bool tense(T &a,const T &b){return b<a?a=b,true:false;}
const long long INF=0x3f3f3f3f3f3f3f3fll;
const int M=500010,N=505;
int m,n,Q;
int len[N];
std::vector<int>a[N],tmpc[N];
int w[M];
std::vector<int>id[M],c[M];
long long g[N][N];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int _,d;
	scanf("%d%d%d%d%d",&_,&n,&m,&d,&Q);
	for (int i=1;i<=m;i++) scanf("%d",&w[i]);
	for (int i=1;i<=n;i++) {
		scanf("%d",&len[i]);
		a[i].resize(len[i]+10),tmpc[i].resize(len[i]+10);
		for (int j=1;j<=len[i];j++) scanf("%d%d",&a[i][j],&tmpc[i][j]);
		for (int j=1;j<=len[i];j++) {
			assert(a[i][j]<M);
			id[a[i][j]].push_back(i);
			c[a[i][j]].push_back(tmpc[i][j]);
		}
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) g[i][j]=i==j?0:INF;
	for (int i=1;i<=m;i++) {
//		printf("%d\n",i);
		assert(id[i].size()==c[i].size());
		for (int j=0;j<(int)id[i].size();j++) {
			for (int k=0;k<(int)id[i].size();k++) {
//				printf("%d %d %d %d\n",j,k,id[i][j],id[i][k]);
				int u=id[i][j],v=id[i][k];
				tense(g[u][v],(long long)c[i][j]+c[i][k]);
				tense(g[v][u],(long long)c[i][j]+c[i][k]);
			}
		}
	}
//	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) printf("g[%d][%d]=%d\n",i,j,g[i][j]);
	for (int k=1;k<=n;k++) {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				tense(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
//	puts("-----------------");
//	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) printf("g[%d][%d]=%d\n",i,j,g[i][j]);
	while (Q--) {
		int u,v;
		scanf("%d%d",&u,&v);
		long long ans=INF;
		for (int i=0;i<(int)id[u].size();i++) {
			for (int j=0;j<(int)id[v].size();j++) {
				tense(ans,(long long)w[u]+w[v]+c[u][i]+c[v][j]+g[id[u][i]][id[v][j]]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
