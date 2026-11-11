#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
int a[500005],c[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++)
	{
		c[i] = a[i] - a[i - 1];
//		cout << c[i] << " ";
	}
//	cout << endl;
	for (int i = 2;i <= n;i++)
	{
		if (c[i] == 0) continue;
		if (c[i] != 0 && m >= c[i] * (i - 1))
		{
			c[1] += c[i];
			c[i] = 0;
//			cout << i << " " << c[i] << endl;
			int t = c[i] * (i - 1);
			m -= t;
		}
		else if (m >= i - 1)
		{
			while (m >= i - 1)
			{
				c[1] += 1;
				c[i] -= 1;
				m -= (i - 1);
			}
		}
//		else
//		{
//			c[1] += 1;
//			c[m + 1] -= 1;
//			m = 0;
//		}
//		cout << m << endl;
	}
//	for (int i = 1;i <= n;i++) cout << c[i] << " ";
	int cnt = 0;
	for (int i = 1;i <= n;i++)
	{
//		cout << c[i] << " ";
		c[i] += c[i - 1];
//		cout << c[i] << endl;
		if (c[i] == c[1]) cnt++;
	}
	cout << cnt;
	return 0;
}
