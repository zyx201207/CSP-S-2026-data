#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
long long n, m, a[500005], ans = 1;
queue <long long> q;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;++i)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	q.push(a[1]);
	for (int i = 2;i <= n;++i)
	{
		m -= (a[i] - a[i - 1]) * q.size();
		q.push(a[i]);
		while (m < 0)
		{
			m += a[i] - q.front();
			q.pop();
		}
		ans = max(ans, (long long)q.size());
	}
	cout << ans << endl;
	return 0;
}
