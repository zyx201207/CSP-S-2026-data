#include <bits/stdc++.h>
using namespace std;

long long a[200005];

bool cmp(long long x,long long y)
{
	return x>y;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool t = 1;
	long long n,m,ans = 0,maxnn;
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]>=4) t=0;
	}
	if(m==1)
	{
		sort(a+1,a+n+1,cmp);
		cout << a[1];
		return 0;
	}
	if(m==n)
	{
		ans = a[1];
		for(int j = 2;j<=n;j++)
		{
			ans &= a[j];
		}
		cout << ans;
		return 0;
	}
	if(m==2)
	{
		long long maxn = 0;
		for(int j = 1;j<=n;j++)
		{
			for(int k = j+1;k<=n;k++)
			{
				maxn = max(maxn,(a[j]&a[k]));
			}
		}
		cout << maxn;
		return 0;
	}
	if(t)
	{
		sort(a+1,a+n+1,cmp);
		ans = a[1];
		for(int j = 2;j<=m;j++)
		{
			ans &= a[j];
		}
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1);
	cout << a[1];
	return 0;
}
