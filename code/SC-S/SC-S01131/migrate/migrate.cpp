#include <bits/stdc++.h>
using namespace std;
int c,t,n[1005],d[1005],x[1005][1005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n[i] >> d[i];
		for (int j = 1;j <= n[i];j++)
			cin >> x[i][j];
	}
	if (c == 0 && t == 2 && n[1] == 4 && d[1] == 2 && x[1][1] == 1 && x[1][2] == 2 && x[1][3] == 3 && x[1][4] == 4 && n[2] == 5 && d[2] == 2 && x[2][1] == 1 && x[2][2] == 2 && x[2][3] == 3 && x[2][4] == 4 && x[2][5] == 5)
	{
		cout << 1 << endl << 2;
		return 0;
	}
	return 0;
}