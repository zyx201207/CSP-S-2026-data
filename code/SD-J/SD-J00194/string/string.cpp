#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;
typedef long long ll;
int n, a[N], pos;
char c[N];
ll L, mid, num[N], idx, sum[N], ctt;
unordered_map<ll, bool> vis;
ll np[N];
ll ans = 0;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i] >> c[i];
		L += a[i], sum[i] = sum[i - 1] + a[i];
	}
	if(L % 2 == 0) mid = (L >> 1);
	else mid = ((L + 1) >> 1);
	for(int i=1; i<=n; ++i) {
		if(sum[i] < mid) {
			num[++idx] = sum[i];
			pos = i;
		}
		else {
			if(L % 2 == 0) num[++idx] = mid, pos = i;
			break;
		}
	}
	for(int i=pos; i<=n; ++i) {
		if(sum[i] > mid) num[++idx] = sum[i] - mid;
	}
	sort(num + 1, num + 1 + idx);
	for(int i=1; i<=idx; ++i) {
		if(!vis[num[i]]) {
			vis[num[i]] = 1;
			np[++ctt] = num[i];
		}
	}
	for(int i=1; i<=ctt; ++i) {
		int pos1 = lower_bound(sum + 1, sum + 1 + n, np[i]) - sum;
		int pos2 = lower_bound(sum + 1, sum + 1 + n, np[i] + mid) - sum;
		char p = c[pos1], q = c[pos2];
		if(p != q) ans += np[i] - np[i - 1];
	}
	cout << ans << '\n';
	return 0;
}
