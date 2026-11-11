#include<bits/stdc++.h>
#define N 500005
#define M 505
#define ll long long
using namespace std;
const ll inf=4e18;
int n,c,m,d,q;
int a[N];
ll dis[M][M];
vector<pair<int,int>> g[N];
int main(){
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin),freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) dis[i][j]=0;
			else dis[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int u,t;
			cin>>u>>t;
			g[u].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=j+1;k<g[i].size();k++){
				dis[g[i][j].first][g[i][k].first]=min((ll)g[i][j].second+g[i][k].second,dis[g[i][j].first][g[i][k].first]);
				dis[g[i][k].first][g[i][j].first]=dis[g[i][j].first][g[i][k].first];
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
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(auto i:g[x]){
			for(auto j:g[y]){
				ans=min(ans,dis[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
}