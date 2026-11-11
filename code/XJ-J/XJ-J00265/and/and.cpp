#include <iostream>
using namespace std;
int main()
{	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[200005];
	cin >> n, m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int x;
	int ans = -1;
	for (int i = 1; i <= n - 1; i++)
	{
		x = a[i];
		for (int j = i; j <= m && j <= n; j++)
		{
			x &= a[j+i];
			if (x > ans)
			{
				ans = x;
			}
		}
	}
	cout << ans;
	return 0;
}
