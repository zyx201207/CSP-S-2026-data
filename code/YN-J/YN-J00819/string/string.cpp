#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s = "";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	long long l = 1, r = n, js = 0;
	while (l < r) {
		if (b[l] == b[r]) {
			long long l1 = a[l], r1 = a[r];
			a[l] -= min(l1, r1);
			a[r] -= min(l1, r1);
		} else {
			js += min(a[l], a[r]);
			long long l1 = a[l], r1 = a[r];
			a[l] -= min(l1, r1);
			a[r] -= min(l1, r1);
		}
		if (a[r] <= 0) {
			r--;
		}
		if (a[l] <= 0) {
			l++;
		}
		//cout << js << " " << l << " " << r << " " << a[l] << " " << a[r] << endl;
	}
	cout << js;
	return 0;
}
