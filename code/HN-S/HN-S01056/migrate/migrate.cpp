#include <iostream>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n;
ll d, x[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i ++) cin >> x[i];
		bool f = 1;
		for (int i = 3; i <= n; i ++)
		{
			if (x[i] - x[i - 1] != x[i - 1] - x[i - 2]) {f = 0; break;}
		}
		if (f)
		{
			if (x[n] - x[n - 1] < d) {cout << "0\n"; continue;}
			for (int i = 1; i <= n; i ++)
			{
				int l = lower_bound(x + 1, x + n + 1, x[i] + d) -x;
			}
		}
	}
	return 0; 
}
