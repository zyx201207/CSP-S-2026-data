#include <bits/stdc++.h> 
using namespace std;

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[200005], maxx = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int x = a[i], ii = i;
		for (int j = ii+1; j <= n; j++)
		{
			for (int k = 1; k <= m; k++)
			{
				x = (x & a[j]);
				ii++;
			}
			cout << x << " ";
			
		}
		maxx = max(maxx, x);
	}
	cout << maxx;
	return 0;
}
