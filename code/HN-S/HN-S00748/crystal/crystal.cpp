#include <bits/stdc++.h>
using namespace std;
int n;
long long m,s[500005],a[500005];
bool check(int x)
{
	long long minn = 1e18;
	for (int i = x;i <= n;i++) minn = min(minn,a[i] * (x - 1) - s[i - 1] + s[i - x]);
	return minn <= m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	int l = 1,r = n;
	while (l < r)
	{
		int mid = r - (r - l) / 2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}
