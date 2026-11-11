#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=5e5+7;
ll n,m,a[N],dp[N],sum,ans=1;
bool flag=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<ll>());
	for(int i=1;i<=n;i++)
	{
		if(i>1)
		{
			sum=a[i-1]-a[i];
		}
		if(i>2&&a[i-1]-a[i]!=sum)
		{
			flag=0;
		}
	}
	if(flag)
	{
		for(int i=n;i>=1;i--)
		{
			ll v=(a[i]-a[n])/sum+1;
			ll k=(a[n]+a[i])*v/2;
			if(k>=m)
			{
				cout<<ans;
				return 0;
			}
			else
			{
				ans++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ll sum=0,cnt=0;
		for(int j=i;j<=n;j++)
		{
			sum+=a[i]-a[j];
			if(sum<=m)
			{
				cnt++;
			}
			if(sum>m||j==n)
			{
				dp[i]=max(dp[i-1],cnt);
				break;
			}
		}
	}
	cout<<dp[n];
	return 0;
}