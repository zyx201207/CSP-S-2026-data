#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxn=-1,ans=-1,a[500005],b[500005],s[500005],c[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++)
		b[i]=a[i]-a[i-1];
	for(ll i=1;i<=n;i++)
		c[i]=c[i-1]+b[i];
	for(ll i=1;i<=n;i++)
		s[i]=s[i-1]+(i-1)*b[i];
	for(ll i=1;i<=n;i++)
	{
		ll l=i,r=n+1;
		while(l<r-1)
		{
			ll mid=(l+r)/2;
			if(s[mid]-s[i-1]-(i-1)*(c[mid]-c[i-1])>m)
				r=mid;
			else
				l=mid;
		}
		maxn=max(l-i+1,maxn);
	}
	cout<<maxn;
	return 0;
}
