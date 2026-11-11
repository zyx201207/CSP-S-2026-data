#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
int n;
ll m, a[N];

bool check(int x)
{
	if (x == 1) return 1;
	ll now = 0;
	for (int i = 1, j = 1; i <= n - x + 1; )
	{
		if (j - i + 1 == x)
		{
			if (now <= m) return 1;
			i++;
			j++;
			now = now - (a[j - 1] - a[i - 2]) + (x - 1) * (a[j] - a[j - 1]);
		}
		else
		{
			j++;
			now += (j - i) * (a[j] - a[j - 1]);
		}
	}
	return 0;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n;
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << "\n";
	return 0;
}

