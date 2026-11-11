#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n, a[N];
char c[N];
ll ans = 0;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i] >> c[i];
	int l = 1, r = n;
	while(l < r)
	{
		int t = min(a[l], a[r]);
		if(c[l] != c[r])
			ans += t;
		a[l] -= t;
		a[r] -= t;
		if(a[l] == 0) l ++;
		if(a[r] == 0) r --;
	}
	cout << ans << '\n';
	return 0;
}
