#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], sum;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	while(m)
	{
		a[1] ++;
		sort(a + 1, a + n + 1);
		m --;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (a[i] == a[1])
		{
			sum ++;
		}
		else
		{
			break;
		}
	}
	cout << sum;
	return 0;
}