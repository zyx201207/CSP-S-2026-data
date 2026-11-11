#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > e[500005];
long long dp[505][505];
int w[500005];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=1;i<=502;i++){
		for(int j=1;j<=502;j++){
			dp[i][j]=1e17;
			if(i==j){
				dp[i][j]=0;
			}
		}
	}
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int xx,yy;
			cin>>xx>>yy;
			for(auto k:e[xx]){
				dp[k.first][i]=dp[i][k.first]=min(dp[i][k.first],(long long)(k.second+yy));
			}
			e[xx].push_back({i,yy});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[j][i]=dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		long long st,ed,mi=1e17;
		cin>>st>>ed;
		for(auto i:e[st]){
			for(auto j:e[ed]){
				mi=min(mi,w[st]+w[ed]+dp[i.first][j.first]+i.second+j.second);
			}
		}
		cout<<mi<<'\n';
	}
	return 0;
}