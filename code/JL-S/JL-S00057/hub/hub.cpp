#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
int u[N], v[N];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, n, k;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++)
		{
			cin >> u[i] >> v[i];
		}
	}
	int m;
	cin>> m;
	if (n == 2 * m + 1)
	{
		for (int i = 1; i <= m; i++)
		{
			u[i] = i;
			v[i] = i + 1; 
		}
		for (int i = m +1; i <= n - 1; i++)
		{
			u[i] = i - m; 
			v[i] = i + 1;
		}
	}
	cout << m;
	return 0;
}
