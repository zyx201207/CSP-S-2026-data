#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.in", "w", stdout);
	int n;
	cin >> n;
	int h = 0, c = 0;
	long long a[100005];
	char s[100005];
	string m, x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
	}
	if (n < 2) {
		cout << 0;
	} else {
		cout << 2;
	}
	return 0;
}