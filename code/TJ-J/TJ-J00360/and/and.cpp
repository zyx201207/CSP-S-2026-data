#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if(m == 1)
	{
		cout << a[n];
		return 0;
	}
	else if(m == n)
	{
		int ans = a[1];
		for(int i = 2; i <= n; i++) ans &= a[i];
		cout << ans;
		return 0;
	}
	else if(m == 2)
	{
		int ans = 0;
		for(int i = n; i > 1; i--) ans = max(ans, a[n] & a[n - 1]);
		cout << ans;
		return 0;
	}
	else if(m == n - 1)
	{
		int ans = a[n];
		for(int i = m; i >= 1; i++) ans &= a[i];
		cout << ans;
		return 0; 
	}
	return 0;
}
