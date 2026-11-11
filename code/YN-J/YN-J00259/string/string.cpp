#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int op;
		char c;
		cin >> op >> c;
		ans += op;
	}
	cout << ans / 2;
	return 0;
}