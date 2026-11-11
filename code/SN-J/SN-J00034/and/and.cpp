#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6; 
long long n, m, a[N], maxn;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + 1 + n);
	maxn = a[n];
	for (int i = n - 1; i > n - m; i--)
	{
		maxn = maxn & a[i];
	}
	cout << maxn;
	return 0;
}
