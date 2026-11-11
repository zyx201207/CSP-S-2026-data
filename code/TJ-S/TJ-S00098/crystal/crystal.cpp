#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, l, r, maxn, j;
long long a[500005], b[500005], c[500005];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1;i < n;i++)
	{
		b[i] = b[i - 1] + i * (a[i] - a[i - 1]);
		c[i] = b[i] - b[i - 1];
	}
	l = 1;
	r = 2;
	while (l < n)
	{
		while (b[r] - b[l] - c[l] <= m && r < n)
		{
			r++;
			if (maxn > r - l + 1)
			{
				maxn = maxn;
			}
			else
			{
				maxn = r - l + 1;
				j = l;
			}
		}
		l++;
	}
	if (c[j])
	{
		cout << j;
		cout << maxn - 1;
	}
	else
	{
		cout << maxn;
	}
	return 0;
} 
