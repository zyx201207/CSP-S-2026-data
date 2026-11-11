#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], b[30];
char c[200005];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int sum = 0;
	string s;
	for (int i = 1; i <= n; i++) {
		int a1;
		cin >> a1 >> c[i];
		a[i] = a1;
		while (a1--) {
			s += c[i];
		}
	}
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}