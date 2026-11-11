#include <bits/stdc++.h>
using namespace std;
int n,l=1,r,ans;
long long m,a[500005],sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		sum+=(a[i]-a[i-1])*(i-1);
		if (sum>m)
		{
			sum-=(a[i]-a[i-1])*(i-1);
			r=i-1;
			ans=i-1;
			break;
		}
	}
	if (r==0)
	{
		cout<<n;
		return 0;
	}
	while (r<=n && l<=n)
	{
		while (sum<=m && r<=n)
		{
			r++;
			sum+=(a[r]-a[r-1])*(r-l);
		}
		r--;
		sum-=(a[r+1]-a[r])*(r-l+1);
		ans=max(ans,r-l+1);
		sum-=a[r]-a[l];
		l++;
	}
	cout<<ans;
	return 0;
}
