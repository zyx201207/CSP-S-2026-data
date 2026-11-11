#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a[200005];
	int n,m,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	ans = a[n];
	for (int i = n - 1;i >= n - m + 1;i--)
	{
		ans = ans && i;
	}
	cout << ans;
	return 0;
}
