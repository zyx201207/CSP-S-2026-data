#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1005,M=1e5+5,inf=1e18,mod=1e9+7;
ll c,m,n,d,q;
ll w[M],k,a[N][N],t[N][N],dp[N][N];
void floyd(){
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
}
signed main () {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) dp[i][j]=inf;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			for(int p=1;p<j;p++){
				dp[a[i][p]][a[i][j]]=dp[a[i][j]][a[i][p]]=min(dp[a[i][p]][a[i][j]],t[i][j]+t[i][p]);
			}
		}
	}
	for(int i=1;i<=m;i++) dp[i][i]=0;
	floyd();
/*	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cout<<dp[i][j]<<' ';
		}
		cout<<'\n';
	}*/
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<'\n';
	}
	return 0;
}

