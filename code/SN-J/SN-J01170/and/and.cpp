//西安市高新第二初级中学 八年级16班 SN-J01170 杨博 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[200005],a[200005];
int n,m;
int res;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i]=a[i];
	}
	int s;
	for(int j=1;j<=n;j++)
	{
		dp[j]=max(dp[j],dp[j]&a[j]);
	}
	sort(dp+1,dp+n+1);
	cout<<dp[n];
	return 0;
}
