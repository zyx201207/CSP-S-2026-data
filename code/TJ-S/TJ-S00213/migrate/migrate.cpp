#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
int c, t, n;
ll d, x[N];
void solve()
{
	int cnt = 0;
	memset(x, 0, sizeof(x));
	cin >> n >> d;
	if(d == 1)
	{
		cout << 0 << '\n';
		return;
	}
	for(int i = 1; i <= n; i++) cin >> x[i];
	ll dd = x[2] - x[1];
	for(int i = 1; i <= n - d; i++)
	{
		if(x[i + d] != x[n]) cnt += (d - dd) / dd;
	}
	cout << cnt << '\n';
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--) solve();
	return 0;
}
