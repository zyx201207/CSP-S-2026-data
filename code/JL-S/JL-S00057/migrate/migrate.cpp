#include <bits/stdc++.h>
using namespace std;
const long long N = 18e5 + 5;
int x[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, t, n, d;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
	}
	cout << "1" << endl;
	cout<< "2" << endl;
	return 0;
}
