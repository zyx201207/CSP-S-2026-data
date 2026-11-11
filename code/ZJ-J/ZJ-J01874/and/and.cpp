#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
long long f[2010][2010];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long ans = 0;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	if(m == n - 1)
	{
		sort(a + 1, a + n + 1);
		for(int i = 2; i <= n - 1; i ++)
		{
			ans = 1ll * (a[i] & a[i + 1]);
		}
	}
	else
	{
		sort(a + 1, a + n + 1);
		for(int i = n - m - 1; i <= n - 1; i ++)
		{
			ans = 1ll * (a[i] & a[i + 1]);
		}
	}
	cout << ans << endl;
	return 0;
}