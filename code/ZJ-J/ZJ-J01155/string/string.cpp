#include <bits/stdc++.h>
using namespace std;

struct node
{
	int n;
	char c;

} a[200005];

int main()
{
	int n;
	long long sum = 0, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %c", &a[i].n, &a[i].c);
		sum += a[i].n;
	}
	long long h = sum / 2;
	int l = 1, r = n;
	while (h != 0)
	{
		if (a[l].n <= h)
		{
			h -= a[l].n;
			while (a[l].n >= a[r].n)
			{
				if (a[l].c != a[r].c) ans += (long long)a[r].n;
				a[l].n -= a[r].n;
				r--;
			}
			a[r].n -= a[l].n;
			if (a[l].c != a[r].c) ans += (long long)a[l].n;
			l++;
		}
		else
		{
			while (h >= a[r].n)
			{
				if (a[l].c != a[r].c) ans += (long long)a[r].n;
				h -= a[r].n;
				r--;
			}
			a[r].n -= h;
			if (a[l].c != a[r].c) ans += (long long)h;
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
