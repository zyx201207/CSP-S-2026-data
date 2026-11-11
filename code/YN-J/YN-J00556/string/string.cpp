#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, cnt = 0;
	cin >> n;
	int a[n] = {};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0, r = l - 1;
	string res[100] = {};
	for (int i = 0; i < n; i++) {
		if (l <= r) {
			l++;
			r--;
		}
	}
	cout << cnt;
	return 0;
}