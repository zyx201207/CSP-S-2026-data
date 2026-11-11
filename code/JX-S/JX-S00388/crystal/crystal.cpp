#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,s[500005],sum[500005];
bool pan(int x)
{
	for(int i=x;i<=n;i++)
	{
		long long num=(x-1)*s[i]-sum[i-1]+sum[i-x];
		if(num<=m) return true;
	}
	return false;
}
int f()
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+(r-l+1)/2;
		if(pan(mid)) l=mid;
		else r=mid-1;
	}
	return l;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=a[i]-a[1];
		sum[i]=sum[i-1]+s[i];
	}
	cout<<f();
	return 0;
}
