#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500001],maxx=-0x3f3f3f3f3f3f;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++)
	{
		ll q=m;
		ll ans=1;
		for(ll j=i-1;j>=1;j--)
		{
			q-=a[i]-a[j];
			ans++;
			if(q<0)
			{
				ans--;
				break;
			}
		}
		if(ans>maxx) maxx=ans;
	}
	cout<<maxx;
	return 0;
}
