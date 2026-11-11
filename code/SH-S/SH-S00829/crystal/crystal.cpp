#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m,a[N],b[N],dp[N];
int maxx;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]-a[i-1];
		if(b[i]!=b[i-1]&&i>2)
		{
			f=0;
		}
	}
	sort(a+1,a+n+1);
	dp[1]=0;
	if(f)
	{
		for(int i=2;i<=n;i++)
		{
			dp[i]=dp[i-1]+i*b[i]-b[i];
			if(dp[i]<=m)
			{
				maxx=i;
			}
			else
			{
				break;
			}
		}
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
			dp[i]=dp[i-1]+i*b[i]-b[i];
			for(int j=i-1;j;j--)
			{
				if(dp[j+1]<=m)
				{
					maxx=max(maxx,j+1);
					break;
				}
				dp[j]=dp[j+1]-a[i]+a[i-j];
			}
		}
	}
	cout<<maxx;
	return 0;
}
