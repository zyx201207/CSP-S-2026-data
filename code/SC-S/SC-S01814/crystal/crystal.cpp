#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N];
int n;
ll m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	bool A=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) A=0;
	}
	sort(a+1,a+1+n);
	ll ans=0;
	if(A)
	{
		ll t=m;
		for(int i=1;i<n;i++)
		{
			t-=(ll)i*(a[i+1]-a[i]);
			if(t<0)
				break;
			ans++;
		}
	}
	else if(n<=5000)
	{
		for(int st=1;st<=n;st++)
		{
			ll res=0,t=m;
			for(int i=st;i<n;i++)
			{
				t-=(ll)i*(a[i+1]-a[i]);
				if(t<0)
					break;
				res++;
			}
			ans=max(ans,res);
		}
	}
	else
	{
		ll res=0;
		ll t=m;
		for(int i=1;i<n;i++)
		{
			t-=(ll)i*(a[i+1]-a[i]);
			if(t<0)
				break;
			res++;
		}
		t=m;
		for(int i=n-1;i>=1;i--)
		{
			t-=a[n]-a[i];
			if(t<0)
				break;
			ans++;
		}
		ans=max(ans,res);
	}
	cout<<ans+1;
	return 0;
}