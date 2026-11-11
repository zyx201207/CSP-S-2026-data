#include<bits/stdc++.h>
#define int long long
const int N=505,M=5e5+5;
int c,n,m,d,q,G[N][N],w[M];
std::vector<std::pair<int,int>>ve[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
	std::cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)std::cin>>w[i];
	for(int i=1,k;i<=n;i++){
		std::cin>>k;
		for(int j=1,a,t;j<=k;j++){
			std::cin>>a>>t;
			ve[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)G[i][j]=0;
			else G[i][j]=1e18;
		}
	}
	for(int _=1;_<=m;_++)
		for(auto i:ve[_])
			for(auto j:ve[_])
				G[i.first][j.first]=std::min(G[i.first][j.first],i.second+j.second);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				G[i][j]=std::min(G[i][j],G[i][k]+G[k][j]);
	for(int x,y;q--;){
		std::cin>>x>>y;
		int ans=1e18;
		for(auto i:ve[x]){
			for(auto j:ve[y]){
				ans=std::min(ans,w[x]+w[y]+i.second+j.second+G[i.first][j.first]);
			}
		}
		std::cout<<ans<<"\n";
	}
	return 0;
}