#include<bits/stdc++.h>
using namespace std;
long long a[500005]; 
long long sum1[500005];
long long sum2[500005],n,m;

long long sum(long long x)
{
	if(x < 0)
	{
		return sum2[-x];
	}
	return sum1[x];
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	long long minn = INT_MAX;
	bool flag = 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] >= 3)
		{
			if(a[i] - a[i - 1] != a[i - 1] - a[i - 2])
			{
				flag = false;
			}
		} 
		if(a[i] < 500005 && a[i] >= 0) sum1[a[i]]++;
		else if(a[i] < 0 && a[i] > -500005) sum2[-a[i]]++;
		minn = min(minn,a[i]);
	}
	if(flag && n >= 3)
	{
		long long op = abs(a[2] - a[1]);
		long long minx = min(a[1],a[n]);
		long long l = 1,r = n;
		long long mid;
		while(l <= r)
		{
			mid = (l + r) / 2;
			int os = (mid * op + op) * mid / 2;
			if(os > m)
			{
				r = mid - 1;
			}
			else
			{
				l = mid + 1;
			}
		}
		cout << l;
		return 0;
	}
	else
	{
		sort(a + 1,a + n + 1);
		long long maxn = -1;
		for(long long i = 1;i <= n;i += sum(a[i]))
		{
			long long ans = sum(a[i]);
			long long s = m;
			for(long long j = a[i] - 1;j >= minn;j--)
			{
				if(sum(j) != 0)
				{
					if(s - (a[i] - j) * sum(j) >= 0)
					{
						ans += sum(j);
						s -= (a[i] - j) * sum(j);
					}
					else
					{
						ans += s / (a[i] - j);
						break;
					}
				}
			} 
			maxn = max(maxn,ans);
		} 
		cout << maxn;
	}
	return 0;
}
