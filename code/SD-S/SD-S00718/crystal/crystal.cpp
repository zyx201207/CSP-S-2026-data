#include <bits/stdc++.h>
using namespace std;
long long a[500005],n,m,maxn,sum[500005],c,s;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++)
	{
		sum[i] = sum[i-1] + a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		long long l = 1,r = i-1,mid = (l+r)/2,ans = 5000000;
		while(l <= r)
		{
			mid = (l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1]) <= m)
			{
				ans = mid;
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		maxn = max(i-ans+1,maxn);
	}
	cout << maxn;
	return 0;
}
