#include <algorithm>
#include <iostream>
using namespace std;
#define Maxn 2000005
#define INF 1e18
typedef long long ll;
int c, t, n;
ll d, x[Maxn];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++) cin >> x[i];
		if (c == 11 || c == 12) 
		{
			ll k = x[2] - x[1];
			if (k >= d) cout << "0\n";
			else
			{
				ll num = d / k * 2 - 1;
				cout << max(0ll, n - num) << '\n';
			}
		} 
		else cout << "0\n";
	}
	return 0;
}
//第一段at 18:01 性质A
