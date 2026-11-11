#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 5e5 + 5;

ll n, m, a[N];

ll pre[N];
bool Check(int mid) {
	for (int i = mid; i <= n; i++) {
		if (pre[i] - pre[i - mid] + m >= a[i] * mid) {
			return true;
		}
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
	} 
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
} // wzHzm 0:19
