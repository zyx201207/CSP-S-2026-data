#include <iostream>
#include <algorithm>
using namespace std;
long long X[2000005], d, n;
long long minn = 9e18, mincnt;
void dis(int x, int y, int cnt, int sum)
{
	if (x == y)
	{
		if (sum < minn)
		{
			minn = sum;
			mincnt = 1;
		}
		else if (sum == minn)
		{
			mincnt++;
		}
		return;
	}
	for (int i = x; i <= y; i++)
	{
		if (sum + X[x] - X[x - 1] <= d)
		{
			dis(i, y, cnt, sum + X[x] - X[x - 1]);
		}
		else
		{
			dis(i - 1, y, cnt + 1, 0);
		}
	}
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		long long cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> X[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				minn = 9e18;
				mincnt = 0;
				dis(i, j, 0, 0);
				if (mincnt == 2)
				{
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}