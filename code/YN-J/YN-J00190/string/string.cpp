#include <bits\stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	for (int i = 1; i <= n; i++) {
		int x;
		char y;
		cin >> x >> y;
		for (int j = 1; j <= x ; j++) {
			s += y;
		}
	}
	long long sum = s.size();
	long long ans = 0;
	for (int i = 0; i < sum / 2; i++) {
		if (s[i] != s[sum - i - 1]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/