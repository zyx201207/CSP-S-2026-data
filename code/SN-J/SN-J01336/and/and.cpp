#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[200002];
long long maxn;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	maxn = a[n];
	for(long long i = n; i > n - m; i--)
	{
		maxn &= a[i];
	}
	
	cout << maxn;
	return 0;
}
