#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,mid,d[500005],ans,x;
bool check (int mid)
{
	x=0;
	for (int i=1;i<=mid;i++)
		x+=i*d[i];
	if (x<=m)
		return true;
	for (int i=2;i+mid<=n;i++)
	{
		x-=a[i+mid-2]-a[i-2];
		x+=d[i+mid-1]*mid;
		if (x<=m)
			return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
		d[i-1]=a[i]-a[i-1];
	for (int i=1;i<=n-1;i++)
		a[i]=d[i]+a[i-1];
	l=1,r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if (check(mid-1))
		{
			ans=max(ans,mid);
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}
