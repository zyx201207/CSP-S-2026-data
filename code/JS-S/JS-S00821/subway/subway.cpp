#include<stdio.h>
#include<vector>
using ll=long long;
using namespace std;
int n,m,d,q;
ll D[505][505],w[500005];
inline void upd(ll &x,ll y){if(x>y) x=y;}
vector<pair<int,int>> G[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%*d%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;++i) scanf("%lld",w+i);
	for(int i=1,k;i<=n;++i){
		scanf("%d",&k);
		for(int j=0,x,y;j<k;++j){
			scanf("%d%d",&x,&y);
			G[x].emplace_back(i,y);
		}
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) D[i][j]=i==j?0:1e18;
	for(int i=1;i<=m;++i){
		for(int j=0;j<G[i].size();++j) for(int k=j+1;k<G[i].size();++k){
			int x=G[i][j].first,y=G[i][k].first,w=G[i][j].second+G[i][k].second;
			upd(D[x][y],w),upd(D[y][x],w);
		}
	}
	for(int k=1;k<=n;++k) for(int i=1;i<=n;++i) for(int j=1;j<=n;++j)
		upd(D[i][j],D[i][k]+D[k][j]);
	while(q--){
		int a,b;scanf("%d%d",&a,&b);
		ll ans=1e18;
		for(auto p:G[a]) for(auto q:G[b])
			ans=min(ans,p.second+q.second+D[p.first][q.first]);
		ans+=w[a]+w[b];
		printf("%lld\n",ans);
	}
}