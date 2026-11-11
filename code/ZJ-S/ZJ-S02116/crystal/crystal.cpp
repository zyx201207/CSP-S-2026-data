#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll n,m;
	vector<ll> a(n);
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	ll l=0,r=0,x=0;
	ll ans=0;
	while (r<n)
	{
		if (x<=m)
		{
			ans=max(ans,r-l+1);
			if (++r>=n)
				break;
			x+=(a[r]-a[r-1])*(r-l);
		}
		else
		{
			x-=a[r]-a[l++];
		}
	}
	cout<<ans;
	return 0;
}
