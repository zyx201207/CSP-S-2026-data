#include<bits/stdc++.h>
using namespace std;
long long w[500005];
vector<pair<long long,long long>> bs[500005];
long long dis[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			bs[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<bs[i].size();j++){
			for(int k=j+1;k<bs[i].size();k++){
				dis[bs[i][j].first][bs[i][k].first]=min(dis[bs[i][j].first][bs[i][k].first],bs[i][j].second+bs[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=min(dis[i][j],dis[j][i]);
			dis[j][i]=min(dis[i][j],dis[j][i]);
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		long long ans=1e18;
		for(int j=0;j<bs[u].size();j++){
			for(int k=0;k<bs[v].size();k++){
				ans=min(ans,dis[bs[u][j].first][bs[v][k].first]+bs[u][j].second+bs[v][k].second);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
}
