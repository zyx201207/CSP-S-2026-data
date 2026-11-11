#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll n,m;
bool check(ll mid)
{
	ll sum=0;
	for(int i = 1;i<=mid;i++)
	{
		sum+=a[mid]-a[i];
		if(sum>m)
		{
			return false;
		}
	}
	if(sum>m)
	{
		return false;
	}
	return true;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll l = 0,r=n;
	while(l<r)
	{
		ll mid=(r-l+1)/2+l;
		if(check(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout << l<<endl;
	return 0;
}
