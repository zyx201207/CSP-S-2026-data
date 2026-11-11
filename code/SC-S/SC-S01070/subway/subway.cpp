#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,cnt,e[505][505],w[500005];
vector<pair<int,int>> g[500505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);cnt=0;
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int T;scanf("%lld",&T);
		while(T--){
			int u,t;scanf("%lld %lld",&u,&t);
			g[u].push_back({m+i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) e[i][j]=1e18;
	for(int i=1;i<=m;i++)
		for(int j=0;j<g[i].size();j++)
			for(int k=j+1;k<g[i].size();k++)
				e[g[i][j].first-m][g[i][k].first-m]=e[g[i][k].first-m][g[i][j].first-m]=min(e[g[i][j].first-m][g[i][k].first-m],g[i][j].second+g[i][k].second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&j!=k&&k!=i) e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
	while(q--){
		int l,r;scanf("%lld %lld",&l,&r);int res=1e18;
		for(int i=0;i<g[l].size();i++)
			for(int j=0;j<g[r].size();j++)
				res=min(res,g[l][i].second+e[g[l][i].first-m][g[r][j].first-m]+g[r][j].second);
		printf("%lld\n",res+w[l]+w[r]);
	}
	return 0;
}