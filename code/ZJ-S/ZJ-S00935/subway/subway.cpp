#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5,inf=1e16;
long long c,n,m,d,q,x,y,ans;
long long cost[N],k[N],dp[505][505];
vector<long long> vec[N],g[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>cost[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dp[i][j]=inf;
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>x>>y;
			vec[x].push_back(i);
			g[x].push_back(y);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<vec[i].size();j++){
			for(int o=j+1;o<vec[i].size();o++){
				dp[vec[i][j]][vec[i][o]]=dp[vec[i][o]][vec[i][j]]=min(dp[vec[i][j]][vec[i][o]],g[i][j]+g[i][o]);
			}
		}
	}
	for(int sw=1;sw<=n;sw++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][sw]+dp[sw][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=inf;
		for(int o=0;o<vec[x].size();o++){
			for(int j=0;j<vec[y].size();j++){
				ans=min(ans,dp[vec[x][o]][vec[y][j]]+cost[x]+cost[y]+g[x][o]+g[y][j]);
			}
		}
		cout<<ans<<'\n';
	}
}
