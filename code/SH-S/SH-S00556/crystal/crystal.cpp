#include <bits/stdc++.h>
using namespace std;
#define N 500050
#define ll __int128
ll a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		a[i]=x;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	ll l=1,r=1;
	int ans=0;
	while(l<=r&&r<=n)
	{
		if((a[r]*(r-l+1)-(s[r]-s[l-1]))<=m)
		{
			ans=max(ans,(int)(r-l+1));
			r++;
		}
		else 
		{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
