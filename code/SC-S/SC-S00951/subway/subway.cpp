#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+10,M=510;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
ll w[N];
vector<pair<int,ll>>g[N];
ll dp[M][M];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dp,0x3f,sizeof(dp)); 
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a=0;
			ll t=0;
			cin>>a>>t;
			for(auto k:g[a]){
				dp[i][k.first]=min(dp[i][k.first],t+k.second);
				dp[k.first][i]=min(dp[k.first][i],k.second+t);
			}
			g[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			} 
		}
	}
	while(q--){
		int x=0,y=0;
		cin>>x>>y;
		ll ans=INF;
		for(auto i:g[x]){
			for(auto j:g[y]){
				ans=min(ans,dp[i.first][j.first]+w[x]+w[y]+i.second+j.second);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
