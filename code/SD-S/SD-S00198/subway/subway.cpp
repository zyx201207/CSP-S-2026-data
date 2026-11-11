#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > v[500010];
long long dp[510][510];
int c,n,m,d,q,w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			v[x].emplace_back(i,y);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dp[i][j]=1e18;
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=j+1;k<v[i].size();k++){
				dp[v[i][j].first][v[i][k].first]=min(dp[v[i][j].first][v[i][k].first],0ll+v[i][j].second+v[i][k].second);
				dp[v[i][k].first][v[i][j].first]=min(dp[v[i][k].first][v[i][j].first],0ll+v[i][j].second+v[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(auto j:v[x])
			for(auto k:v[y]) ans=min(ans,dp[j.first][k.first]+j.second+k.second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
}
//RP++
