#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
};
int a[1000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		s[i] = n;
		if (s[i] == a[i]) {
			ans++;
		} else {
			cout << 0;
		}
	}
	cout << ans;

	return 0;
}