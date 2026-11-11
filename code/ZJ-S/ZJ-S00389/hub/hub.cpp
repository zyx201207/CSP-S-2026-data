#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
vector<int>g[N],vv;
int sz[N],ff[N][2],ans,n,m,vis[N];
void dfs1(int x,int fa){
	for(auto i:g[x]){
		if(i==fa)continue;
		sz[i]=sz[x]+1;
		dfs1(i,x);
	}
}
void solve(){
	scanf("%lld%lld",&n,&m);
	for(int i=2;i<=n;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	printf("%lld\n",(n+1)/2-1);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%lld%lld",&c,&T);
	while(T--)solve();
	return 0;
}
