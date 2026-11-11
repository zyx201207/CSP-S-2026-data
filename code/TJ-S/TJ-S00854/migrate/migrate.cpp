#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long l[2000001];
long long n,m;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	while (t--) {
		cin>>n>>m;
		long long ans=0;
		for (long long i=0;i<n;i++) {
			cin>>l[i];
		}
		long long dp[n+1][n+1],num[n+1][n+1];
		for (long long i=0;i<n;i++) {
			long long la_j=i;
			for (long long j=i;l[j]-l[i]<=m && j<n;j++) {
				dp[i][j]=1;
				num[i][j]=1;
				la_j=j;
			}
			for (long long j=la_j+1;j<n;j++) {
				long long minum=LONG_LONG_MAX;
				long long cnt=0;
				for (long long k=j-1;(l[j]-l[k]<=m) && k>=0;k--) {
					if (minum==num[i][k]) {
						cnt+=dp[i][k];
					}else if (minum<num[i][k]){
						continue;
					}
					else {
						minum=num[i][k];
						cnt=1;
					}
				}
				dp[i][j]=cnt;
				num[i][j]=minum+1;
				if (dp[i][j]==2) {
					ans++;
				}
				else if (dp[i][j]==0) {
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
