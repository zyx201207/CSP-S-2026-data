#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int n, ans = 0;
long long m, a[500010], p[110], t;

void onetonine()
{
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		int now = 0;
		long long sum = 0;
		for (int j = i; j >= 1; j--)
		{
			if (sum + a[i] - a[j] > m)
				break;
			now++;
			sum += a[i] - a[j];
		}
		ans = max(ans, now);
	}
	cout << ans << '\n';
}

void AB()
{
	m /= t;
	m *= 2;
	long long fin = 0;
	while (1ll * (fin * fin + fin) <= m)
		fin++;
	fin--;
	cout << min(1ll * n, fin + 1) << '\n';
}

void tentotwelve()
{
	int a1 = 0, a2 = 0;
	for (int i = 1; i <= n; i++)
	{
		p[a[i]]++;
		if (p[a[i]] > a1)
			a1 = p[a[i]], a2 = i;
	}
	int now = 0;
	long long sum = 0;
	for (int i = a2; i >= 1; i--)
	{
		if (sum + a[a2] - a[i] > m)
			break;
		now++;
		sum += a[a2] - a[i];
	}
	cout << now << '\n';
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	bool flag = 1, flag2 = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (abs(a[i]) > 100)
			flag2 = 0;
		if (i > 2 && !(a[i] - a[i - 1] == a[i - 1] - a[i - 2]))
			flag = 0;
		t = abs(a[i] - a[i - 1]);
	}
	if (n <= 5000)
		onetonine();
	else if (flag)
	{
		AB();
	}
	else if (flag2)
		tentotwelve();
	return 0;
}
