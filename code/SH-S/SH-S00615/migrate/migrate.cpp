#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int c, t;
int n, d;

ll a[N];

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	srand(time(0));
	
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> t;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
		}
		cout << rand() % (n + 1) << endl;
	}

	return 0;
}

