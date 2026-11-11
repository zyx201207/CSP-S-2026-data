#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long cha[500010];
int n;
unsigned long long m;
long long sum;
int ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i)
			cha[i] = a[i] - a[i - 1];
		//cout << cha[i] << ' ';
	}
	//cout << '\n';
	sort(a, a + n);
	for (int l = 0, r = 0; r < n && l < n;) {
		//cout << sum << '\n';
		//cout << "l=" << l << "   r=" << r << '\n';
		if (sum <= m) {
			ans = max(r - l + 1, ans);
			r++;
			sum += (r - l) * (a[r] - a[r - 1]);
		} else {
			l++;
			sum -= a[r] - a[l - 1];
		}
	}
	cout << ans;
}