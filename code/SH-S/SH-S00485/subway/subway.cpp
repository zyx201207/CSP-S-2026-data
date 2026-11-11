#include<bits/stdc++.h>
using ll=long long;
int c,n,m,D,q;
const int maxn=505,maxm=5e5+5;
int w[maxm];
std::vector<std::pair<int,int>> to[maxm]; 
ll d[maxn][maxn];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++){
		std::cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k; std::cin>>k;
		for(int j=1;j<=k;j++){
			int u,x; std::cin>>u>>x;
			to[u].push_back({i,x});
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=m;i++){
		int sz=to[i].size();
		for(int j=0;j<sz;j++){
			auto [u,x1]=to[i][j];
			for(int k=j+1;k<sz;k++){
				auto [v,x2]=to[i][k];
				d[u][v]=d[v][u]=std::min(d[u][v],(ll)x1+x2);
			}
		}
	}
	for(int i=1;i<=n;i++) d[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=std::min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	while(q--){
		int u,v; std::cin>>u>>v;
		ll best=1e18;
		for(int i=0;i<to[u].size();i++){
			auto [p1,x1]=to[u][i];
			for(int j=0;j<to[v].size();j++){
				auto [p2,x2]=to[v][j];
				best=std::min(best,x1+x2+d[p1][p2]);
			}
		}
		std::cout<<best+w[u]+w[v]<<"\n";
	}
	//std::cerr<<std::clock()*1000.0/CLOCKS_PER_SEC<<"ms\n";
}
