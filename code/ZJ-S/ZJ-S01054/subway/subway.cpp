#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+10;
const int M=510;
const int inf=2e18;
int c,n,m,d,q;
int w[N];
int dis[M][M];
struct node{
	int v,w;
};vector<node> G[N];

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int u,w;
			cin>>u>>w;
			G[u].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			dis[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:G[i]){
			for(auto y:G[i]){
				dis[x.v][y.v]=min(x.w+y.w,dis[x.v][y.v]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=inf;
		for(auto a:G[x]){
			for(auto b:G[y]){
				ans=min(ans,a.w+b.w+dis[a.v][b.v]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

