#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans, x;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	x = a[(n+1)/2];
	for(int i = (n+1)/2;i >= 1;i--)
	{
	   	if(abs(a[i]- a[(n+1)/2]) <= m)
	   	{
	   		a[i] = x;
	   		m -= abs(a[i] - a[(n+1)/2]);
	   	}
	}
	for(int i = 1;i <= n;i++)
		if(a[i] == x)
			ans++;
	cout << ans;
	return 0;
}

