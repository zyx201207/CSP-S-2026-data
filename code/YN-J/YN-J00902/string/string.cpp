#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 10;
int n, a[N], sum = 0;
string s[N];
bool flag = false, u;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
		sum += a[i];
	}
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i + 1]) {
			flag = true;
		}
	}
	if (!flag) {
		cout << 0 << endl;
		return 0;
	}
	if (sum == n) {
		cout << n - 1 << endl;
		return 0;
	}
	return 0;
}