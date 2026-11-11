#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long dp[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		dp[i]=k;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>i;j--)
		{
			dp[j]=max(dp[j],dp[j-1]&dp[i]);
		}
	}
	cout<<dp[n];
}

