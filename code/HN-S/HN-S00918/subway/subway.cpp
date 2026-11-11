#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
int dis[505][505],w[500005];
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	return;
}
vector<pair<int,int>>mp[500005]; 
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,len;i<=n;i++){
		cin>>len;
		while(len--){
			int v,w;
			cin>>v>>w;
			mp[v].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto u:mp[i]){
			for(auto v:mp[i]){
				if(u.first!=v.first){
					dis[u.first][v.first]=min(dis[u.first][v.first],u.second+v.second);
				}
			}
		}
	}
	Floyd();
	while(q--){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(auto u:mp[x]){
			for(auto v:mp[y]){
				ans=min(ans,u.second+v.second+dis[u.first][v.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
	return 0;
}
