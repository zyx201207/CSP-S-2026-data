#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long read()
{
	long long x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <='9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
long long a[N];
long long s[N];
long long maxx[N];
long long h[N];
long long c[N];
int f = 1; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n = read(),m = read();
	for (int i = 1;i <= n;i++)
	{
		a[i] = read();
		c[i] = a[i] - a[i - 1];
		if (c[i] != c[i - 1] && i != 1)
		{
			f = 0;
		}
	}  
	if (f == 1)
	{
		int l= 1,r = n;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (mid * c[2] > m)
			{
				r = mid - 1; 
			}
			else
			{
				l = mid + 1;
			}
		 } 
		 cout << l - 1;
		 return 0;
	}
	sort(a + 1,a + n + 1);
	long long ans = 0;
	for (int i = 1;i <= n;i++)
	{
		maxx[i] = max(maxx[i - 1],a[i]);
		s[i] = s[i - 1] + (maxx[i] - maxx[i - 1]) * (i - 1) + maxx[i] - a[i];
		h[i] = max(maxx[i] - a[h[i - 1]],maxx[i] - a[i]);
		if (s[i] > m)
		{
			if (s[i] - maxx[i] + a[h[i]] <=m)
			{
				s[i] -= (maxx[i] - a[h[i]]); 
				
			}
		}
		else
		{
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}

