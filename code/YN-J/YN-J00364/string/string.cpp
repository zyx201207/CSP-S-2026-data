#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
char c[N];
string s = " ";
int n;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		while (a[i]--) {
			s += c[i];
		}
	}
	int L = s.size() - 1;
	int ans = 0;
	for (int i = 1; i <= L / 2; i++) {
		if (s[i] == s[L + 1 - i]) {
			ans++;
		}
	}
	cout << L / 2 - ans;
	return 0;
}


