#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],sum[500005],mx=-1e18,mn=1e18;
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if((sum[i]-sum[i-x]+m)/x>=a[i])
			return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(check(mid))
			l=mid+1;
		else
			r=mid-1;
		cout<<l<<" "<<r<<endl;
	}
	cout<<l-1;
	return 0;
}