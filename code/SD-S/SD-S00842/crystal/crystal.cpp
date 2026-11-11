#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],c[500005];
int n,m,z = 0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int l = 5e17,r = -5e17;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		r = max(r,a[i] + m);
		l = min(l,a[i]);
	}
	sort(a + 1,a + n + 1);
	for (int i = l;i <= r;i++)
	{
		int x = 0;
		for (int j = 1;j <= n;j++)
		{
			if (i - a[j] >= 0)
			{
				c[++x] = i - a[j];
			}
		}
		sort(c + 1,c + x + 1);
		int v = 0,k = 0;
		for (int j = 1;j <= x;j++)
		{
			v += c[j];
			k++;
			if (v == m)
			{
				z = max(z,k);
			}
			if (v > m)
			{
				z = max(z,k - 1);
				break;
			}
		}
		if (v > m)
		{
			z = max(z,k - 1);
		}
	}
	cout << z;
	return 0;
}

