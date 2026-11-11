#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],s[500005],l=1,r,mid,ans;
bool check(ll x)
{
	for(int i=x;i<=n;i++)
	{
		ll k=s[i]-s[i-x]+m;
		k/=x;
		if(a[i]<=k)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid)==1)
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
} 
