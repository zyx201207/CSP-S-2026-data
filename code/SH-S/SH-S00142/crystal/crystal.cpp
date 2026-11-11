#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10;
int n, m, ppA = 1, ppB = 1, ans, a[N];

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != i) ppA = 0;
		if (i > 2 && a[i]-a[i-1] != a[i-1]-a[i-2]) ppB = 0;
	}
	sort(a+1, a+n+1);
	if (ppA) {
		for (; ans*(ans+1)/2 <= m; ans++);
		cout << ans << "\n";
		return 0; 
	}
	if (ppB) {
		int tmp = 0;
		for (int j = n-1; j >= 1; j--)
		{
			if (tmp+a[n]-a[j] <= m)
				tmp += a[n]-a[j], ans++;
			else break;
		}
		cout << ++ans << "\n";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0, cnt = 1;
		for (int j = i-1; j >= 1; j--)
		{
			if (tmp+a[i]-a[j] <= m)
				tmp += a[i]-a[j], cnt++;
			else break;
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
