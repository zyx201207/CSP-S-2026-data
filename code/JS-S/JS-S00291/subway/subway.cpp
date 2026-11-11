#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template<class _Tp>
void updmi(_Tp &a,_Tp b){
	a=min(a,b);
}

const int N = 500+5;
const int M = 5e5+5;

int __TEST_ID__;

ll G[N][N];
vector<array<int,2>> ways[M];
int n,m,d,q;
int w[M];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&__TEST_ID__);
	scanf("%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int ccs;
		scanf("%d",&ccs);
		for(int j=1;j<=ccs;j++){
			int x,dd;
			scanf("%d%d",&x,&dd);
			ways[x].push_back({i,dd});
		}
	}
	memset(G,0x3f,sizeof(G));
	for(int i=1;i<=n;i++)
		G[i][i]=0;
	for(int i=1;i<=m;i++)
		for(auto u : ways[i])
			for(auto v : ways[i]) if(u[0]!=v[0])
				updmi(G[u[0]][v[0]],(ll)u[1]+v[1]),
				updmi(G[v[0]][u[0]],(ll)u[1]+v[1]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				updmi(G[i][j],G[i][k]+G[k][j]);
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(auto uw : ways[u])
			for(auto vw : ways[v]){
				int uid=uw[0],ud=uw[1];
				int vid=vw[0],vd=vw[1];
				ans=min(ans,ud+vd+G[uid][vid]);
			}
		ans=ans+w[u]+w[v];
		printf("%lld\n",ans);
	}
	return 0;
}