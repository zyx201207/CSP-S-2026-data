#include <bits/stdc++.h>
using namespace std;
/*====================*/
using LL = long long;
/*====================*/
#define endl '\n'
/*====================*/
const int N = 5e5 + 10;
/*====================*/
LL a[N];
/*====================*/
LL temp[N];
/*====================*/
LL d[N];
/*====================*/
LL ans;
/*====================*/
void Solve(void)
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) temp[i] = a[i];
	sort(temp + 1, temp + n + 1);
	int cand = (n + 1) / 2; LL candval = temp[cand];
	for (int i = 1; i <= n; ++i) d[i] = abs(a[i] - candval);
	sort(d + 1, d + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (d[i] == 0) ++ans;
	}
	for (int i = 1; i <= n && m >= 0; ++i)
	{
		if (d[i] == 0) continue;
		++ans; m -= d[i];
	}
	cout << ans << endl;
}
/*====================*/
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr); 
	int t = 1; // cin >> t;
	while (t--) Solve();
	return 0;
}
