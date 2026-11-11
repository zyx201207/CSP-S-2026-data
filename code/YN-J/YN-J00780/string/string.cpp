#include <bits/stdc++.h>
using namespace std;

struct node {
	int a;
	string s;
};
node a[200010];

bool hw(string s) {
	int r = s.size() - 1, l = 0;
	bool f = 0;
	while (l >= r) {
		if (s[l] == s[r]) {
			l++;
			r--;
			f = 1;
		} else {
			return false;
		}
	}
	if (f == 1) {
		return true;
	}
}

int zh(string s) {
	int ans = 0;
	int r = s.size() - 1, l = 0;
	bool f = 0;
	while (l >= r) {
		if (s[l] != s[r]) {
			l++;
			r--;
			ans++;
		} else {
			l++;
			r--;
		}
	}
	return ans;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string c;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].a >> a[i].s;
		for (int j = 0; j < a[i].a; j++) {
			c += a[i].s;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (hw(c)) {
			cout << 0;
			return 0;
		} else {
			ans = zh(c);
		}
	}
	cout << ans;
	return 0;
}