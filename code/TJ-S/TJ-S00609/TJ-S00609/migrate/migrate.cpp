#include <bits/stdc++.h>
using namespace std;
int c, n;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> n;
	for (int i = 1;i <= n;i++)
	{
		int x, y, a[100005];
		cin >> x >> y;
		for (int j = 1;j <= x;j++)
		{
			cin >> a[i];
		}
		cout << (x - 1) / y << endl;
	}
	return 0;
}
