#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],dp[20005][20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	    cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sort(a,a+i);
		dp[i][1]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,m);j++){
			dp[i][j]=max(dp[i][j],dp[i][j-1]&a[i]);
		}
	}
	printf("%lld",dp[n][m]);
	return 0;
} 
