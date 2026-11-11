#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500009];
long long cha[500009];
long long clac(long long x,long long y)
{
	return (y-x)*a[y]-(cha[y-1]-cha[x-1]);
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(long long i = 1;i<=n;i++)
	{
		cha[i] += cha[i-1];
		cha[i] += a[i];
	}
	long long res = 0;
	for(long long i = 1;i<=n;i++)
	{
		long long l = 1,r = i;
		while(l<r)
		{
			long long mid = (l+r)/2;
			if(clac(mid,i)>m)
			{
				l = mid+1;
			}
			else
			{
				r = mid;
			}
		}
		res = max(res,(i-r+1));
	}
	cout << res;

	return 0;
}