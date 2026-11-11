#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int N=505,M=5e5+10,P=998244353;
vector<pair<int,int> >g[M];
int dis[N][N],a[M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,k,q;
	cin>>c>>n>>m>>k>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int z;
		cin>>z;
		for(int j=1;j<=z;j++){
			int x,t;
			cin>>x>>t;
			g[x].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int z=g[i].size();
		for(int x=0;x<z;x++){
			for(int y=0;y<z;y++){
				if(x==y) continue;
				int u=g[i][x].first,v=g[i][y].first;
				int w=g[i][x].second+g[i][y].second;
				dis[u][v]=min(dis[u][v],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||i==k||k==j) continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto U:g[x]){
			for(auto V:g[y]){
				int u=U.first,v=V.first;
				int w=U.second+V.second;
				ans=min(ans,dis[u][v]+w);
			}
		}
		ans+=a[x]+a[y];
		cout<<ans<<'\n';
	}
	return 0;
}
//CSP-S2026 rp++
//15:31
//100pts
