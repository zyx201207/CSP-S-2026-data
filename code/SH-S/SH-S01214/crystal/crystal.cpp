#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
long long sum[500005];


bool check(int l, int r)
{
	long long use = (r - l) * a[r] - sum[r - 1] + sum[l - 1];
	if (use > m)
		return false;
	return true;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1;
	int ans = 0;
	for (int r = 1; r <= n; r++)
	{
		sum[r] = sum[r - 1] + a[r];
		while (!check(l, r))
			l++;
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
	return 0;
	// 写下这行注释保我不挂分qwq 
}
