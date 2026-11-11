#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M=2e5+5;
const LL inf=0x3f3f3f3f3f3f3f3f;
int c,n,m,d0,q,w[M],k[505],a[505][M],t[505][M],x,y;LL d[M][505];
vector<pair<int,int> >e[M];
LL dfs(int now,int fa,int r){
	if(now==y){
		return t[fa][r];
	}
	if(d[now][fa]!=inf) return d[now][fa];
	for(auto i:e[now]){
		if(i.second!=k[i.first])
			d[now][fa]=min(d[now][fa],(fa==i.first?0:t[fa][r]+t[i.first][i.second])+dfs(a[i.first][i.second+1],i.first,i.second+1));
	}
	return d[now][fa];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d0,&q);
	for(int i=1;i<=m;++i) scanf("%d",&w[i]);
	for(int i=1;i<=n;++i){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];++j)
			scanf("%d%d",&a[i][j],&t[i][j]),e[a[i][j]].push_back({i,j});
	}
	while(q--){
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		memset(d,0x3f,sizeof d);
		printf("%lld\n",dfs(x,0,1)+w[x]+w[y]);
	}
	return 0;
}