#include <iostream>
#include <string>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s = "";
	int n;
	cin >> n;
	long long a, x = 0;
	char c;
	for (long long i = 1; i <= n; i++) {
		cin >> a >> c;
		while (a--) {
			s += c;
			x++;
		}
	}
	long long l = 0, r = x - 1;
	long long cnt = 0;
	while (l <= r) {
		if (s[l] != s[r]) {
			cnt++;
		}
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}
