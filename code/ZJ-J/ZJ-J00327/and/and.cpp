#include <bits/stdc++.h>
using namespace std;

int one(unsigned long long x)
{
	int res = 0;
	while (x > 0)
	{
		res += x % 2;
		x /= 2;
	}
	return res;
}

bool cmp1(unsigned int x1, unsigned int x2)
{
	return one(x1) != one(x2) ? one(x1) > one(x2) : x1 > x2;
}

bool cmp2(unsigned int x1, unsigned int x2)
{
	return x1 > x2;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	unsigned int a[n], ans1, ans2;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, cmp1);
	ans1 = a[0];
	for (int i = 1; i < m; i++) ans1 &= a[i];
	sort(a, a + n, cmp2);
	ans2 = a[0];
	for (int i = 1; i < m; i++) ans2 &= a[i];

	cout << max(ans1, ans2);
	
	return 0;
}
