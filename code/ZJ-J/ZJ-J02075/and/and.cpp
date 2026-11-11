#include <bits/stdc++.h>
using namespace std;
long long a[2007];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, maxn = 0;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] > maxn)
			man = a[i];
	}
	if(m == 1)
	{
		cout << maxn;
		return 0;
	}
//	if(m == n)
//	{
//		int ans = a[0];
//		for(int i = 1; i < n; i++)
//			ans = ans & a[i];
//		cout << ans;
//	}
//	if(m == n - 1)
//	{
//		int ans = a[0];
//		for(int i = 1; i < n; i++)
//			ans = ans & a[i];
//		cout << ans;
//	}
	return 0;
}