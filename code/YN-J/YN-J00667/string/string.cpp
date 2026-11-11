#include <bits/stdc++.h>
using namespace std;
int sum, ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string s = "";
	for (int i = 1; i <= n; i++) {
		int x;
		char sx;
		cin >> x >> sx;
		sum += x;
		for (int j = 1; j <= x; j++) {
			s += sx;
		}
	}
	for (int i = 0; i < sum / 2; i++) {
		if (s[i] != s[sum - i - 1])
			ans++;
	}
	cout << ans;
	return 0;
}

