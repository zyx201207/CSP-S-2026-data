#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
long long sum, num;
char c[200005];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%s", &a[i], &c[i]);
	    sum += a[i];
	}
	int v = 0;
	for(int i = 1, l = n; i <= n; i++)
	{
		if(v >= sum / 2 + 1)
		{
			break;
		}
		if(a[i] <= a[l])
		{
			v += a[i];
			if(c[i] != c[l])
			{
				num += a[i];
			}
			a[l] -= a[i];
		}
		else
		{
			v += a[l];
			if(c[i] != c[l])
			{
				num += a[l];
			}
			a[i] -= a[l];
			l--;
			i--;
		}
	}
	cout << num;
	return 0;
}