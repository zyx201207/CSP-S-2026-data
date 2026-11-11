#include<bits/stdc++.h>
using namespace std;
long long a[200005],dp[200005];
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++)
		for(long long j=m;j>=1;j--)
			if(j==1) dp[j]=max(dp[j],a[i]);
			else dp[j]=max(dp[j-1]&a[i],dp[j]);
	cout<<dp[m];
	return 0;
}
