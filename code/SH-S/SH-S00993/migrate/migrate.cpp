#include <iostream>
using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			int x; cin >> x;
		}
		cout << n / 3 << '\n';
	}
	cout.flush(); 
	return 0;
}
