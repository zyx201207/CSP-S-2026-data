#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000005], b[1000005][5], ans = -1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	b[1][1] = 1;
	b[1][2] = m;
	for (int i = 2;i <= n;i++)
	{
		b[i][1] = 1;
		if (b[i - 1][2] >= a[i] - a[i - 1])
		{
			b[i][1] = b[i - 1][1] + 1;
			b[i][2] = b[i - 1][2] - (a[i] - a[i - 1]);
		}
		else
		{
			long long t = m;
			int j = i - 1;
			while (t >= a[i] - a[j] && j > 0) 
			{
				t -= (a[i] - a[j]);
				b[i][1]++;
				j--;
			}
			b[i][2] = t;
		}
		ans = max(ans, b[i][1]);
	}
	cout << ans;
	return 0;
}
