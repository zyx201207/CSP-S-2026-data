#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,maxx=0,maxn=0;
long long a[200010],dp[2010][2010];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		if(i==1){
			cnt=a[i];
			maxx=a[i];
		}else{
			cnt=cnt&a[i];
			maxx=max(maxx,a[i]);
		}
	}
	if(m==1) {
		cout<<maxx<<endl;
		return 0;
	} else if(m==n) {
		cout<<cnt<<endl;
		return 0;
	}
	dp[1][1]=a[1];
	maxn=a[1];
	for(long long i=2; i<=n; i++) {
		dp[i][1]=max(dp[i-1][1],a[i]);
		maxn=maxn&a[i];
		for(long long j=2; j<=min(m,i); j++) {
			if(i==j) {
				dp[i][j]=maxn;
				break;
			}
			dp[i][j]=dp[i-1][j];
			for(long long k=max(1ll,m-1); k<i; k++) {
				dp[i][j]=max(dp[i][j],dp[k][j-1]&a[i]);
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
