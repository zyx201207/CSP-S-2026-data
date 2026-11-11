//高文轩 铜川市第二中学 SN-J00654
#include <bits/stdc++.h>
using namespace std;

int n, m, a[500010], b[500010], t[500010], tg[500010];

int main ()
{
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1, a + n + 1);
	int pd = 1;
	for (int i = 1;i <= n; i++)
	{
		if (a[i] != b[i])
		pd = 0;
	}
	t[0] = 0;
	if (pd)
	{
		for (int i = n; i <= 1; i++)
		{
			t[i]++;
		}
		for (int i = n; i >= 1; i++)
		{
			if (t[a[i + 1]] < 2)
			{
				tg[a[i]] += i;
			}	
		}
		for (int i = 1; i <= m; i++)
		{
			cout << tg[i] << ' ';
		}
		return 0;
	}
	return 0;
}
