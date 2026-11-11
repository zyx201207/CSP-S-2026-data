#include <iostream>
#include <string>
using namespace std;
int a[200005];
char c[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		string t;
		for (int num = 1; num <= a[i]; num++) {
			t = t + c[i];
		}
		s = s + t;
	}
	int length = s.size();
	int ans = 0;
	for (int i = 0, j = length - 1; i < (length + 1) / 2; i++, j--) {
		if (s[i] != s[j]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}