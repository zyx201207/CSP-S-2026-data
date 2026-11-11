#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, p;
	cin >> n >> p;
	int s = 0;
	for (int i = 1; i <= n - 1; i++) {
		s = i * (p + 2);
	}
	cout << s;
	return 0;
}