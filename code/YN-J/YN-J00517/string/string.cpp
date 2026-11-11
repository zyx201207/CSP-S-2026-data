#include <bits/stdc++.h>
using namespace std;

int n;
struct node {
	int s;
	int c;
} t[200005];

long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		char y;
		cin >> x >> y;
		t[i].s = x;
		t[i].c = y;
	}
	int l = 1, r = n;
	while (r >= l) {
		int k = 1;
		if (t[l].c == t[r].c) {
			k = 0;
		}
		if (t[l].s > t[r].s) {
			if (k)
				ans += t[r].s;
			t[l].s -= t[r].s;
			t[r].s = 0;
			r--;
		} else if (t[l].s == t[r].s) {
			if (k)
				ans += t[r].s;
			t[l].s = 0;
			t[r].s = 0;
			l++;
			r--;
		} else {
			if (k)
				ans += t[l].s;
			t[r].s -= t[l].s;
			t[l].s = 0;
			l++;
		}
	}
	cout << ans;
	return 0;
}