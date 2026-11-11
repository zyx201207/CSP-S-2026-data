#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n;
long long a[N], m, s[N];
bool check(int x)	{
	for (int i = x; i <= n; ++i)	{
		if (a[i] * x <= s[i] - s[i - x] + m)	return true;
	}
	return false;
}
int main()	{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)	scanf("%lld", a + i);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)	s[i] = s[i - 1] + a[i];
	int l = 0, r = n;
	while (l < r)	{
		int mid = l + r + 1 >> 1;
		if (check(mid))	l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0;
}
