#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

using ll = long long;

static inline void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

int main(void) {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	FastIO();
	int n{};
	cin >> n;
	string s = "";
	for (int i = 0; i < n; i++) {
		int m{};
		char c{};
		cin >> m >> c;
		for (int i = 0; i < m; i++)
			s.push_back(c);
	}
	ll l = s.length();
	bool isStringValid = true;
	for (ll i = 0, j = l - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			isStringValid = false;
			break;
		}
	}
	if (isStringValid == true)
		cout << 0;
	else if (isStringValid == false) {
		ll cnt = 0;
		for (ll i = 0, j = l - 1; i < j; i++, j--) {
			if (s[i] != s[j])
				cnt++;
		}
		cout << cnt;
	}


	return 0;
}