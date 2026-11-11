#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int n,m,d,q;
int w[500005];
int dp[2005][2005];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	cin>>c;
	cin>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n+m; i++) {
		for(int j=1; j<=n+m; j++) {
			dp[i][j]=INT_MAX;
		}
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k; j++) {
			int a,b;
			cin>>a>>b;
			dp[a][m+i]=b;
			dp[m+i][a]=b;
		}
	}
	for(int k=1; k<=n+m; k++) {
		for(int i=1; i<=m+n; i++) {
			for(int j=1; j<=n+m; j++) {

				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				dp[j][i]=dp[i][j];
			}
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}
