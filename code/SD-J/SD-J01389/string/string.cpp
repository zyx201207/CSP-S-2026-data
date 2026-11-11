#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
unsigned long long ans = 0;
char b[200005];
unsigned long long sum;
unsigned long long l=1,r=sum;
int find(unsigned long long x)
{
	int re = 1;
	while(x > a[re])
	{
		x -= a[re];
		re++;
	}
	return re;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
		sum += a[i];
	}
	long long rest = min(a[1],a[n]),p = (a[1] >= a[n] ? 1 : 2);
	while(true)
	{
		if (p == 1)
		{
			if (b[find(l)] != b[find(r)])
			{
				ans += min(rest,a[find(r)]);
			}
			l += min(rest,a[find(r)]);
			r -= min(rest,a[find(r)]);
			if (rest >= a[find(r)])
			{
				p = 1;
				rest = rest - a[find(r)];
			}
			if (a[find(r)] > rest)
			{
				p = 2;
				rest = a[find(r)] - rest;
			}
		}
		if (p == 2)
		{
			if (b[find(l)] != b[find(r)])
			{
				ans += min(a[find(l)],rest);
			}
			l += min(a[find(l)],rest);
			r -= min(a[find(l)],rest);
			if (a[find(l)] > rest)
			{
				p = 1;
				rest = a[find(l)] - rest;
			}
			if (a[find(r)] > a[find(l)])
			{
				p = 2;
				rest = rest - a[find(l)];
			}
		}
		if (a[find(l)] >= n/2)
		{
			break;
		}
	}
	cout << ans;
	return 0;
}
