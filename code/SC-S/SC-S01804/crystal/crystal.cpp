#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], ans;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	if(m == 0)
	{
		cout << 0 << "\n";
		return 0;
	}
	for(int i = 1; i <= n; i++)	
	{
		long long yui = 0;
		for(int j = 1; j <= i; j++)
		{
			yui += a[i] - a[j];
		}
		if(yui > m)
		{
			cout << i - 1 << "\n";
			return 0;
		}
	}
	return 0;
}