#include<bits/stdc++.h>
using namespace std;
const int mx=5.1e5;
bool vis[mx];
long long w[mx],dis[509][509];
struct pt{
	long long to,dis;
};
vector<pt> G[mx];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,d,n,m,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			G[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=4e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto u0:G[i]){
			for(auto u1:G[i]){
				dis[u0.to][u1.to]=min(dis[u0.to][u1.to],u0.dis+u1.dis);
			}
		}
	}
	//clog<<dis[2][1]<<"}";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[j][k]=min(dis[j][k],dis[j][i]+dis[i][k]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=4e18;
		for(auto u0:G[x]){
			for(auto u1:G[y]){
				ans=min(ans,u0.dis+dis[u0.to][u1.to]+u1.dis);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}//Liu Boyan
