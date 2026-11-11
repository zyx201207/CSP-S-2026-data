#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500005], bx;

bool B = 1;

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i == 1)continue;
		if (i == 2)bx = a[i] - a[i - 1];
		if (a[i]-a[i-1]!=bx)B=0;
	}
	if (B)
	{
		int cnt = 0;
		while (bx * cnt <= m)
		{
			m-=bx*cnt;
			cnt++;
		}
		cout << cnt << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			cnt++;
			continue;
		}
		if ((i - 1) * (a[i] - a[i - 1]) > m) break;
		cnt++;
		m -= (i - 1) * (a[i] - a[i - 1]);
 	}
 	cout << cnt << endl;
	return 0;
}
