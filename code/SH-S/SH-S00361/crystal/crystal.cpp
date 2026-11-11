#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 5000005
typedef long long ll;
int n;
ll m, ans, a[Maxn], s[Maxn];
bool P(ll l, ll r)
{
	ll len = r - l;
	return (((len * a[r]) - (s[r - 1] - s[l - 1])) <= m);
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	ll l = 1, r = 1;
	while (l <= n)
	{
		while (P(l, r + 1) && r + 1 <= n) ++r;
		//cout << l << ' ' << r << '\n';
		ans = max(ans, r - l + 1);
		++l;
	}
	cout << ans;
	return 0;
}
//at 14:48
//上午自以为AK，实则挂飞/kk
//下午T1又是简单题，别挂了，++rp 
