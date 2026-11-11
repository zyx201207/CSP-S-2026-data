#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, m, sum = 0;
long long a[N], b[N];

struct node {
	int d, x;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	b[1] = a[1];
	for (int i = 2; i <= n; i++) {
		b[i] = a[i] + b[i - 1];
	}


//Ç°×ººÍ
	int l = 1, r = 1;
	int ans = 0;
	while (l <= r && r <= n) {
		//cout << "l: " << l << " r: " << r << " m: " << a[r] * (r - l) - (b[r - 1] - b[l - 1]) << '\n';
		if (a[r] * (r - l) - (b[r - 1] - b[l - 1]) <= m) {
			ans = max(ans, r - l + 1);
			r++;
		} else {
			l++;
		}
	}
	cout << ans;
	return 0;
}






