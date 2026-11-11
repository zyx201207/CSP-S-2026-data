#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 10;

int c, t;
int n;
long long d, dis[maxn];

void solve ()
{
	cin >> n >> d;
	long long a, b;
	cin >> a;
	for (int i = 2; i <= n; i++) 
	{
		cin >> b;
		dis[i - 1] = b - a;
		a = b;
	}
	if (c == 11 || c == 12)
	{
		int delta = d / dis[1];
		//int mind = 
	}
}

int main ()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

