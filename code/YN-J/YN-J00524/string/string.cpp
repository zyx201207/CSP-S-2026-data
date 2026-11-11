#include <bits/stdc++.h>
using namespace std;
long long  a[200000];

int main() {
	freopen (" string.in", "r", stdin);
	freopen (" string.out", "w", stdout);
	int n;
	cin >> n;
	string c;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> a [i] >> c;
		for (int i = 1; i <= a[i]; i++)
			s += c;
	}
	int half = s.size() / 2 + 1, ans = 0;
	for (int i = 1; i <= half; i++)
		if (a[i] != a[2 * half - i])
			ans++;
	cout << ans;
	return 0;
}