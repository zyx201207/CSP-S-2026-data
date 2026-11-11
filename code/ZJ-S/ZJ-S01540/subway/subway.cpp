#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18,N=505,M=1005;
int w[500005];
int k[505];
vector<pair<int,int> > g[500005];
int dist[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int aij,tij;
				cin>>aij>>tij;
				g[aij].push_back({i,tij});
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=inf;
			}
			dist[i][i]=0;
		}
		for(int i=1;i<=m;i++){
			for(auto j:g[i]){
				for(auto k:g[i]){
					dist[j.first][k.first]=min(dist[j.first][k.first],j.second+k.second);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
				}
			}
		}
		//cout<<dist[1][2];
		while(q--){
			int x,y;
			cin>>x>>y;
			int ans=inf;
			for(auto i:g[x]){
				for(auto j:g[y]){
					ans=min(ans,i.second+j.second+dist[i.first][j.first]);
					//cout<<i.second<<" "<<j.second<<" "<< dist[i.first]<<'\n';
				}
			}
			cout<<ans+w[x]+w[y]<<'\n';
		}
}