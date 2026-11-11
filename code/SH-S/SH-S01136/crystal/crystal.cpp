#include <bits/stdc++.h>
#define use(x) using std::x;
#define pb push_back
#define fastread ios::sync_with_stdio(false),cin.tie(0);
#define freo(a,b) freopen(a,"r",stdin),freopen(b,"w",stdout);
#define fi first
#define se second
#define int long long

use(cin)use(sort)use(max)use(cout)use(ios)

const int maxn=500005;
int a[maxn];
signed main()
{
	freo("crystal.in","crystal.out")
	fastread
	
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	sort(a,a+n);
	int sum=0,l=0,r=0;
	for (int i=n-1;i>=0;i--)
	{
		sum+=a[n-1]-a[i];
		if (sum>m)
		{
			sum-=a[n-1]-a[i];
			l=i+1;
			r=n-1; 
			break;
		}
	}
	
	int ans=r-l+1;
	while (l>0)
	{
		// cout<<sum<<'\n';
		sum-=(r-l)*(a[r]-a[r-1]);
		r--;
		while (l>0 && sum<=m)
		{
			l--;
			sum+=a[r]-a[l];
		}
		if (sum>m)
		{
		sum-=a[r]-a[l];
			l++;
			
		}
		ans=max(ans,r-l+1);
		// cout<<l<<r<<'\n';
	}
	cout<<ans;
}
