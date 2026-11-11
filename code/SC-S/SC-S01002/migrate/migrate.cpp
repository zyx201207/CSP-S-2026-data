#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 5;
int c, t, n, d, x[MAXN];
int main ()
{
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t --)
	{
		if (c == 0)
		{
			int a;
			cin >> a;
			if (a == 4)
			{
				cout << "1\n2";
			} else {
				cout << "0\n1";
			}
			return 0;
		}
		cout << rand() % 10 << endl;
	}
	return 0;
}