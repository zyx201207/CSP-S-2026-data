#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],c[500005],b[500005];
long long dp[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=1;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long maxn=LONG_LONG_MIN;
	long long t=0;
	for(int i=1;i<=n;i++){
		t=dp[i-1]*a[i]-(b[i-1]-b[i-dp[i-1]-1]);
		if(t<=m){
			dp[i]=dp[i-1]+1;
		}
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,dp[i]);
	}
	cout<<maxn;
	return 0;
}