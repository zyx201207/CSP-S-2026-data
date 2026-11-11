//马知遥 西安交通大学附属中学 SN-S00380  
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dp[1005][1005];
const int INF=1e18;
int w[1000005];
vector< pair<int,int> >qw[1000005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q,x,t;
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int ac,tc;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>ac>>tc;
			qw[ac].push_back({i,tc});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				dp[i][j]=INF;
			}
			else{
				dp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<qw[i].size();j++){
			for(int k=j+1;k<qw[i].size();k++){
				int u=qw[i][j].first;
				int v=qw[i][k].first;
				int w=qw[i][k].second+qw[i][j].second;
				dp[u][v]=w;
				dp[v][u]=w;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dp[i][k]!=INF && dp[k][j]!=INF && dp[i][j]>(dp[i][k]+dp[k][j])){
					dp[i][j]=dp[i][k]+dp[k][j];
					dp[j][i]=dp[i][k]+dp[k][j];
				}
			}
		}
	}
	int st,en;
	while(q--){
		int ans=INF;
		cin>>st>>en;
		for(int i=0;i<qw[st].size();i++){
			for(int j=0;j<qw[en].size();j++){
				int w1=qw[st][i].second;
				int w2=qw[en][j].second;
				int u=qw[st][i].first;
				int v=qw[en][j].first;
				if(dp[u][v]!=INF){
					ans=min(ans,dp[u][v]+w[st]+w[en]+w1+w2);
				}
			}
		}
		cout<<ans<<"\n";
	}
}
