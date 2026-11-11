#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 5e5 + 10;
int n, m;
int a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	
	int ans = 1;
	for (int l = 1, r = 1, len = 1, sum = 0; r <= n; ++r, ++len) {
		sum += a[r];
		while (a[r] * len - sum > m) {
			sum -= a[l];
			l++;
			len--;
		}
		ans = max(ans, len);
	}
	
	cout << ans << endl;
	
	return 0;
}
