#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n;
ll m, a[N], ans = 1;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	ll d = a[2] - a[1];
	ll i = d;
	while(m > 0 && m >= i)
	{
		ans++;
		m -= i;
		i += d;
	}
	for(int i = ans + 1; i <= n; i++) if(a[i] == a[ans]) ans++;
	cout << ans;
	return 0;
}
