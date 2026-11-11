#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,q;
int w[500005];
vector<pair<int,int> >a[500005];
int dis[5005][5005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int u,v;
			cin>>u>>v;
			a[u].push_back({i,v});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto u:a[i]){
			for(auto v:a[i]){
				if(u.first==v.first){
					continue;
				}
				int uu=u.first;
				int vv=v.first;
				dis[uu][vv]=min(dis[uu][vv],u.second+v.second);
				dis[vv][uu]=min(dis[vv][uu],u.second+v.second);
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
		int ans=w[x]+w[y];
		int ll=1e18;
		for(auto u:a[x]){
			for(auto v:a[y]){
			//	cout<<u.first<<" "<<v.first<<endl;
				ll=min(ll,dis[u.first][v.first]+u.second+v.second);
			}
		}
		cout<<ans+ll<<"\n";
	}
}
