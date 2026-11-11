#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],dp[500005],ans[500005],maxn[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		if(maxn[a[i-1]]==i-1)
		{
			dp[i]+=ans[a[i-1]];
		}
		ans[a[i]]+=dp[i];
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}
