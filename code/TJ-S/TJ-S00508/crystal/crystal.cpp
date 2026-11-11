#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n;
long long m, a[maxn], sum[maxn], now, ans;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	long long l = 1;
	for(long long r = 1; r <= n; r++) {
		while(now > m) {
			now -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
		now += (a[r+1] - a[r]) * (r - l + 1);
	}
	cout << ans << endl;
	return 0;
}
