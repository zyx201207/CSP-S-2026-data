#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
#define ll long long
int n;
ll m, a[N], ans, temp, sum[N];
ll divide(int l, int r, int fin, ll num) {
	ll ff = fin;
	int mid = (l + r) >> 1;
	while (l < r) {
		ll lmid = mid;
		ll ch = (ff - lmid + 1) * num - (sum[fin] - sum[mid - 1]);
		if (m >= ch)
			r = mid;
		else l = mid + 1;
		mid = (l + r) >> 1;
	}
	if (m < num - a[fin])
		return 0;
	return fin - l + 1;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++) {
		sum[i] = a[i] + sum[i - 1];
		if (a[i] == a[i - 1] && i)
			temp++;
		else {
			ans = max(ans, temp);
			temp = 1;
			temp += divide(1, i - 1, i - 1, a[i]);
		}
	}
	ans = max(ans, temp);
	cout << ans;
	return 0;
}
