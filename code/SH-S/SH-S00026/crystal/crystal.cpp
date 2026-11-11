#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647
long long a[500005] = {};
long long diff[500005] = {};
long long Prefix[500005] = {};
long long pr[500005] = {};
int n;
long long m;
bool check(int x)
{
	for (int i = x - 1; i < n; i++)
	{
		int left = i - x + 1;
		long long now = (x - 1) * Prefix[i] - (pr[i] - pr[left]);
		if (now <= m) return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++)
	{
		diff[i] = a[i] - a[i - 1];
	}
	for (int i = 1; i < n; i++)
	{
		Prefix[i] = diff[i] + Prefix[i - 1];
	}
	for (int i = 1; i < n; i++)
	{
		pr[i + 1] = Prefix[i] + pr[i];
	}
	int ans = INF;
	int l = 1, r = n, mid;
	while (l != r)
	{
		mid = (l + r) / 2;
		if (check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else r = mid;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
