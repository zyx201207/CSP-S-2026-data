#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000005];
long long f[10000005];
long long cnt;
bool s(long long x)
{
	for(int i=1;i<=n;i++)
	if(x*a[i]-(f[i]-f[i-x-1])<=m) return true;
	return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		f[i]=a[i]+f[i-1];
	}
	long long l=1,r=n;
	while(l<=r)
	{
		long long mid=l+(r-l)/2;
		if(s(mid)) 
		{
			cnt=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout << cnt;
	return 0;
}