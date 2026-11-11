#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	vector<char> a;
	while (n--) {
		long long l;
		char c;
		cin >> l >> c;
		while (l--) {
			a.push_back(c);
		}
	}
	long long sum = 0;
	long long len = a.size();
	for (int i = 0; i < len / 2; i++) {
		if (a[i] != a[len - 1 - i]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}