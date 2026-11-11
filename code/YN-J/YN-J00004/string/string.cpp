#include <bits/stdc++.h>
using namespace std;
char a[100005];

int main() {
	freopen("string.in", "r", stdin);
	//freopen("string.out", "w", stdout);
	long long n, len = 0, ans = 0;
	cin >> n;
	while (n--) {
		char x;
		int cnt;
		cin >> x >> cnt;
		while (cnt--)
			a[len++] = x;
	}
	int mid = len / 2;
	for (int i = 0; i < mid; i++) {
		if (a[i] != a[len + 1 - i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
