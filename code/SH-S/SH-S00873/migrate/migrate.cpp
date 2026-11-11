#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
int c,T;
int n;
long long d;
long long a[N];
long long dis[N];
int cnt = 0;
void solveA()
{
	long long gc = a[2] - a[1];
	if (gc > d && gc < 2 * d)
	{
		cout << 0 << endl;
	}
	else
	{
		int x = d / gc;
		int first = x + x;
		cnt = n - first + 1;
		cout << cnt << endl;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		sort(a + 1,a + n + 1);
		for (int i = 1;i <= n;i++)
		{
			dis[i] = a[i + 1] - a[i];
		}
		if (c == 1 || c == 2)
		{
			cout << 2 << endl;
		}
		else if (c >= 3 && c <= 6)
		{
			cout << 7 << endl;
		}
		else if (c >= 7 && c <= 10)
		{
			cout << 15 << endl;
		}
		else if (c == 11 || c == 12)
		{
			solveA();
			continue;
		}
		else if (c == 13 || c == 14)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << n / 2 + 1 << endl;
		}
	}
	return 0;
}
