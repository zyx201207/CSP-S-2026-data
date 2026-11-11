#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000000],dp[1000000],maxn;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dp[i]=a[i];
	}
	for(int j=2;j<=n;j++)
	{
		dp[j]=max(dp[j-1],dp[j]&a[j]);
	}
	cout<<dp[m];
	return 0;
} 
