#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long dp[2005][20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(long long j=0;j<=n;j++){
		for(long long k=0;k<=m;k++){
			dp[j][k]=a[j];
		}
	}
	dp[0][0]=0;
	for(long long i=0;i<=n;i++){
		for(long long j=i;j>=0;j--){
			for(long long k=a[i];k>=j;k--){
				dp[j][k]=max(dp[j-1][k],dp[j][k-a[i]]&a[i]);
			}
		}
	}
	printf("%lld",dp[n][m]);
	return 0;
}/*
*/
