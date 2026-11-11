#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int n, m, a[100005], ans, cmp = 1;
int main(int argc, char** argv) {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if (i == 1)
		{
			ans = a[i];
			continue;
		}
		if (m == 1)
			ans = max(ans, a[i]);
		if (m == 2)
		{
			for (int j = 1; j < i; j ++)
			{
				ans = max(ans, a[i] & a[j]);
			}
		}
		else if (m == n)
		{
			ans = ans & a[i];
		}
		else
		{
			cmp = 0;
		}
	}
	if (cmp)
		cout << ans;
	else if (n <= 20)
	{	
		for (int i = 1; i <= m; i ++)
		{
			for (int j = 1; j <= n; i ++)
			{
				if(i == 1 && j == 1)
				{
					ans = a[j];
				}
				if (ans <= ans & a[j])
				{
					ans = ans & a[j];
					a[j] = 0;
				}
			}
		}
		cout << ans;
	}
	else if (m == n - 1)
	{
		int tmp = 0;
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j <= n; j ++)
			{
				if (i == 1 && j == 1)
				{
					tmp = a[j];
					continue;
				}
				if (i == j)
				{
					continue;
				}
				else
				{
					tmp = tmp & a[j];
				}
			}
			ans = max(ans, tmp);
		}
	}
	else
	{
		for (int i = 1; i <= n; i ++)
		{
			ans = max(ans, a[i]);
		}
		cout << ans;
	}
	return 0;
}