#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[200011];
char c[200011];
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	ll ls=a[1],rs=a[n];
	while(l<r)
	{
		ll minn=min(ls,rs);
		if(c[l]==c[r])
		{
			ls-=minn;
			rs-=minn;
		}
		else
		{
			ls-=minn;
			rs-=minn;
			ans+=minn;
		}
		if(ls==0)
		{
			l++;
			ls=a[l];
		}
		if(rs==0)
		{
			r--;
			rs=a[r];
		}
	}
	cout<<ans;
	return 0;
}
