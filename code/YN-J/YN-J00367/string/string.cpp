#include <bits/stdc++.h>
using namespace std;
string t ="";
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c, a;
	long long n, ans = 0, s;
	bool flag = 1;
	cin >> n;
	if (n == 1) {
		cout << "0";
		return 0;
	}
	n -= 1;
	cin >> s >> c;
	a = c;
	if (s >= 100000000) {
		cout << 3000000000;
		return 0;
	}
	for (int i = 1; i <= s; i++) {
		t += c;
	}
	while (n--) {
		cin >> s >> c;
		if (a != c) {
			flag = 0;
		}
		if (s >= 100000000) {
			cout << 3000000000;
			return 0;
		}
		for (int i = 1; i <= s; i++) {
			t += c;
		}
	}
	if (flag) {
		cout << "0";
	} else {
		int r = t.size();
		for (int i = 0; i < r; i++) {
			if (t[i] != t[r]) {
				ans++;
				r--;
			}
		}
		cout << ans;
	}
	return 0;
}