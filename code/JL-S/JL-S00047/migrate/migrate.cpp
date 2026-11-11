#include <bits/stdc++.h>
using namespace std;
int c, t, n, d;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		long long a, b, ch;
		bool is = 1;
		for(int i = 0; i < n; i++)
		{
			b = a;
			cin >> a;
			if(i == 1)
			{
				ch = a - b;
			}
			if(i > 1 && ch != a - b)
			{
				is = 0;
			}
		}
		if(!is)
		{
			cout << "0\n";
			continue;
		}
		if(ch * 2 > d || n < (d / ch) * 2)
		{
			cout << "0\n";
			continue;
		}
		cout << n - 3 << '\n';
	}
	return 0;
}
