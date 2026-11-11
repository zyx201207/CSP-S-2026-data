#include <bits/stdc++.h>
using namespace std;
long long n, sum = 0, ss = 0, ans = 0;
string q, h;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		char z;
		cin >> t >> z;
		ss = sum;
		sum += t;
		for (int j = ss; j <= sum - 1; j++) {
			q += z;
		}
	}
	for (int i = sum - 1; i >= sum / 2; i--) {
		h += q[i];
	}
	for (int i = 0; i <= h.size() - 1; i++) {
		if (h[i] != q[i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
