#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=1e5+10;
int dp[510][510];
vector<pair<int,int>>v[N];
int w[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			v[a].push_back({i,t});
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++){
		for(pair<int,int> &to1:v[i]){
			for(pair<int,int> &to2:v[i]){
				dp[to1.first][to2.first]=min(dp[to1.first][to2.first],to1.second+to2.second);
				dp[to2.first][to1.first]=min(dp[to2.first][to1.first],to1.second+to2.second);
			}
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
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(pair<int,int> to1:v[x]){
			for(pair<int,int> to2:v[y]){
				ans=min(ans,to1.second+to2.second+dp[to1.first][to2.first]);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}