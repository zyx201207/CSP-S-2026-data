#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[505];
long long w[20005];
int dp[20005][20005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=m;i++) {
		for(int j=0;j<=m;j++) {
			dp[i][j]=1e9;
		}
	}
	for(int i=1;i<=m;i++) {
		cin>>w[i];
	}
	for(int i=1;i<=n;i++) {
		cin>>k[i];
		int a[25],t[25];
		for(int j=0;j<=25;j++) {
			a[j]=0;
			t[j]=0;
		}
		for(int j=1;j<=k[i];j++) {
			cin>>a[j]>>t[j];
			for(int p=1;p<j;p++) {
				if((t[p]+t[j])<dp[a[p]][a[j]]) {
					dp[a[p]][a[j]]=(t[p]+t[j]);
				}
			}
		}
	}
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=m;j++) {
			if(dp[i][j]!=1e9) dp[j][i]=dp[i][j];
			if(dp[j][i]!=1e9) dp[i][j]=dp[j][i];
			for(int p=1;p<=m;p++) {
				if((dp[i][p]+dp[p][j])<dp[i][j]) dp[i][j]=(dp[i][p]+dp[p][j]);
			}
		}
	}
	for(int i=1;i<=q;i++) {
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]+w[x]+w[y]<<endl;
	}
	return 0;
}

