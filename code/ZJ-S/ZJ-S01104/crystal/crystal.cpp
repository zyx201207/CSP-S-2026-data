#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
int n;
ll a[MAXN], pre[MAXN], ans, m;
bool check(int i, ll mid) {
	ll need = a[i] * mid - (pre[i - 1] - pre[i - mid - 1]);
	return need <= m;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL); 
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		ll l = 1, r = i - 1;
		ll cnt = 0;
		while (l <= r) {
			ll mid = l + r >> 1;
			if (check(i, mid)) {
				cnt = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}
		ans = max(ans, cnt + 1);
	}
	cout << ans;
	return 0;
}
