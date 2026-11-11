#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);


	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	long long a;
	string c, s = "";
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s += c;
		}
	}
//	cout << s << "\n";
	long long cnt = 0;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}