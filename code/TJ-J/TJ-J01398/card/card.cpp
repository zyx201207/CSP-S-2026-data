#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], ans[500010];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		++ans[a[i]];
	}
	for(int i = 1; i <= m; ++i)
	{
		ans[i] = ans[i] + ans[i - 1];
		cout << ans[i] << " ";
	}
	return 0;
}
