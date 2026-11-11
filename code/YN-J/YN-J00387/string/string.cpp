#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long int n;
	long long int ans = 0;
	string s;
	cin >> n;
	while (n--) {
		long long a;
		char s1;
		cin >> a >> s1;
		while (a--) {
			s += s1;
		}
	}

	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[s.size() - i - 1]) {
			ans++;
		}
	}
	cout << ans ;

	return 0;
}