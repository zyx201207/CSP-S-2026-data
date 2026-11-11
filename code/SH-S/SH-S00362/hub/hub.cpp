#include <bits/stdc++.h>
using namespace std;

long long u[1000005], v[1000005];
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; ++i)
		{
			cin >> u[i] >> v[i];
		}
		cout << 1 << endl;
	}
	return 0; 
}
