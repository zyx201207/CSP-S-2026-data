#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], s[N];
#define get(l, r) (a[r] * (r - l + 1) - (s[r] - s[l - 1]))
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
	int ans = 0;
	for(int i = 1, l = 1; i <= n; i ++)
	{
		while(get(l, i) > m && l <= i) l ++;
		ans = max(ans, i - l + 1);
	}
	cout << ans << "\n";
	return 0;
}