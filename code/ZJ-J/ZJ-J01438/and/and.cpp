#include<bits/stdc++.h>
#define int long long
using namespace std;
const int k=pow(2,30)-1;
int n,m;
int a[200005];
int dp[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	dp[0]=k;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			dp[j]=max(dp[j-1]&a[i],dp[j]);
		}
	}
	printf("%lld",dp[m]);
	return 0;
}
