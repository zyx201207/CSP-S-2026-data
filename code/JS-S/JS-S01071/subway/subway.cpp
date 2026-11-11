#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=507,M=5e5+7;
int f[N][N],a[M];
vector<int> vc[M],vw[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof f);
	int n,m,q;
	scanf("%*d%lld%lld%*d%lld",&n,&m,&q);
	for (int i=1;i<=m;++i)
		scanf("%lld",a+i);
	for (int i=1,k,x,y;i<=n;++i){
		scanf("%lld",&k),f[i][i]=0;
		while (k--) scanf("%lld%lld",&x,&y),vc[x].push_back(i),vw[x].push_back(y);
	}
	for (int i=1;i<=m;++i){
		int k=vc[i].size();
		for (int p=0;p<k;++p)
			for (int q=0;q<k;++q)
				f[vc[i][p]][vc[i][q]]=min(f[vc[i][p]][vc[i][q]],vw[i][p]+vw[i][q]);
	}
	for (int k=1;k<=n;++k)
		for (int i=1;i<=n;++i)
			for (int j=1;j<=n;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while (q--){
		int u,v,mn=1e18;
		scanf("%lld%lld",&u,&v);
		int ku=vc[u].size(),kv=vc[v].size();
		for (int i=0;i<ku;++i)
			for (int j=0;j<kv;++j)
				mn=min(mn,vw[u][i]+f[vc[u][i]][vc[v][j]]+vw[v][j]);
		printf("%lld\n",mn+a[u]+a[v]);
	}
	return 0;
}