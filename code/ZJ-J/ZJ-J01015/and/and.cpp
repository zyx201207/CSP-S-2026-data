#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int dp[200010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--){
			if(j>1) dp[j]=max(dp[j],dp[j-1]&a[i]);
			else dp[j]=max(dp[j],a[i]);
		}
	cout<<dp[m];
	return 0;
}
