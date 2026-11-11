#include <bits/stdc++.h>

using namespace std;

int n, ans = -1, ani = 1;
long long m;
long long a[500005], c[500005];

void f(long long dm)
{
	for (int i = 1; i < n; i++)
	{
		int t = 1;
		long long s = 0;
		for (int j = i + 1; j <= n; j++)
		{
			if (s + c[j] * (j - i) <= dm)
			{
				s += (c[j] * (j - i));
				t++;
			}
			else break;
		}
		
		if (t > ani)
		{
			ans = s;
			ani = t;
		}
	}
	
	return;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		c[i] = a[i] - a[i - 1];
	}
	
	f(m);
	
	printf("%d", ani);
		
	return 0;
} 
