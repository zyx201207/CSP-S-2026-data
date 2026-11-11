#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=510,M=5e5+10,inf=1e18+7;
int cid,n,m,d,q,w[M];
int dp[N][N];
vector<pair<int,int> >g[M];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(i==j)dp[i][j]=0;
		else dp[i][j]=inf;
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int pos,r;cin>>pos>>r;
			g[pos].push_back({i,r});
		}
	}
	for(int i=1;i<=m;i++){
		for(pair<int,int> t1:g[i])
		for(pair<int,int> t2:g[i]){
			dp[t1.first][t2.first]=min(dp[t1.first][t2.first],t1.second+t2.second);
			dp[t2.first][t1.first]=min(dp[t2.first][t1.first],t2.second+t1.second);
		}
	}
	for(int t=1;t<=n;t++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)dp[i][j]=min(dp[i][j],dp[i][t]+dp[t][j]);
	while(q--){
		int x,y;cin>>x>>y;
		int ans=inf;
		for(pair<int,int> t1:g[x])
		for(pair<int,int> t2:g[y])ans=min(ans,dp[t1.first][t2.first]+t1.second+t2.second+w[x]+w[y]);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
