#include <bits/stdc++.h>
using namespace std;
string a;
int n;

long long pd() {
	long long b = 0;

	for (int i = 0 ; i <= a.size() / 2; i++) {

		if (a[i] != a[a.size() - 1 - i])
			b++;
	}

	return b;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	while (n--) {
		long long x;
		char y;
		cin >> x >> y;
		string b(x, y);
		a += b;
	}

	cout << pd();
	return 0;
}
