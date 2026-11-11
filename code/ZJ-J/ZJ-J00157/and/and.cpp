#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long a[N];
long long dp[N][35];
long long sum[N][35];
long long v[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1; i<=n; i++) {
		for(long long j=1; j<=31; j++) {
			dp[i][j]=(a[i]%2);
			sum[i][j]=sum[i-1][j]+dp[i][j];
			a[i]/=2;
		}
	}
//	for(long long i=1; i<=n; i++) {
//		for(long long j=1; j<=31; j++) {
//			cout<<dp[i][j];
//		}
//		cout<<'\n';
//	}
	long long b=0;
	long long ans=0;
	for(long long k=31; k>=1; k--) {
		if(b==1) {
			long long t=0;
			for(long long i=1; i<=n; i++) {
				if(v[i]!=-1&&dp[i][k]==1) {
					t++;
				}
			}
			if(t>=m) {
//				cout<<k<<'wxq';
				ans+=(1<<(k-1));
				for(long long i=1; i<=n; i++) {
					if(v[i]!=-1&&dp[i][k]==1) 
					    continue;
					v[i]=-1;
				}
			}
		} else if(sum[n][k]>=m) {
//			cout<<k<<' ';
			ans+=(1<<(k-1));
			b=1;
			for(long long i=1; i<=n; i++) {
				if(dp[i][k]!=1)
					v[i]=-1;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
*/
