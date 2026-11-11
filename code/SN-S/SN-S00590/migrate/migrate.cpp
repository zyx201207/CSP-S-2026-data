#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[5005],s[5005];
vector<int> ve[5005];
int dp[5005][5005],dd[5005][5005];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);

	cin>>c>>t;
	while(t--) {
		memset(dd,0,sizeof(dd));
		cin>>n>>d;
		for(int i=1; i<=n; ++i) {
			cin>>x[i];
		}

		memset(dp,0x3f,sizeof(dp));
		for(int i=1; i<=n; ++i) {
			dp[i][i]=0;
			for(int j=i+1; j<=n; ++j) {
				if(x[j]-x[i]<=d) {
					dp[i][j]=dp[j][i]=1;
				}
			}
		}

		for(int k=1; k<=n; ++k) {
			for(int i=1; i<=n; ++i) {
				for(int j=1; j<=n; ++j) {
					if(i==j)continue;
					if(dp[i][j]==dp[i][k]+dp[k][j])dd[i][j]++;
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
				}
			}
		}
		int cnt=0;
		for(int i=1; i<=n; ++i) {
			for(int j=1; j<=n; ++j) {
				if(dd[i][j]==3){
					cnt++;
					dd[j][i]=0;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
