#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
vector<int> e[514];
int dis[514][514];
vector<pair<int,int> > to[514514];
int w[514514];
main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//ans not forget to add w[i]!
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			to[a].pb({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto x:to[i]){
			for(auto y:to[i]){
				int u=x.fi,v=y.fi;
				int w=x.se+y.se;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
//		cout<<endl;
//	}
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=1e18;
		for(auto x:to[u]){
			for(auto y:to[v]){
//				cout<<x.fi<<" "<<y.fi<<" "<<x.se<<" "<<y.se<<" "<<dis[x.fi][y.fi]<<endl;
				ans=min(ans,x.se+y.se+dis[x.fi][y.fi]);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	} 
}
//100 pts?
