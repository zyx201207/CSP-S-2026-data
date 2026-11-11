#include<bits/stdc++.h>
using namespace std;
int a[200005];
int dp[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int k=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int t=dp[1];
		dp[1]=max(dp[1],a[i]);
		if(t!=dp[1])
		{
			k=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==k)continue;
		for(int j=m;j>=1;j--)
		{
			dp[j]=max(dp[j],dp[j-1]&a[i]);
		}
	}
	cout<<dp[m];
	return 0;
}
