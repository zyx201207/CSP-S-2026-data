#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], b[200005], o = 1, j = 1, sum, u[2];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	u[1] = a[2] - a[1];
	for (int i = 1; i <= n; i++)
	{
		if (a[i] - a[i + 1] == u[1])
		{
			u[0] = 1;
		}
	}
	if (!u[0])
	{
		for (; sum * (sum - 1) * abs(u[1]) < m; sum++)
		{
			;
		}
		cout << sum * 2 - 1;
	}
	else
	{
		sort(a + 1, a + n + 1);
		for (int i = 2; i <= n; i++)
		{
			sum += (a[i] - a[i - 1]) * (i - 1);
			while (sum > m)
			{
				sum -= (a[i] - a[j++]);
			}
			o = max(o, i - j + 1);
		}
		cout << o;
	}
	return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//long long n, m, a[500005], o = 1, j = 1, sum;
//int main()
//{
//	freopen("crystal.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a + 1, a + n + 1);
//	for (int i = 2; i <= n; i++)
//	{
//		sum += (a[i] - a[i - 1]) * (i - 1);
//		while (sum > m)
//		{
//			sum -= (a[i] - a[j++]);
//		}
//		o = max(o, i - j + 1);
//	}
//	cout << o;
//	return 0;
//}
