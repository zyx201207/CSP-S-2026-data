#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, number = 0;
	cin >> n;
	long long b;
	string c;
	string a;
	for (int i = 0; i < n; i++) {
		cin >> b >> c;
		for (int i = 0; i < b; i++) {
			a += c;
		}
	}
	for (int i = 0; i < a.size() / 2; i++) {
		if (a[i] != a[a.size() - i - 1]) {
			number++;
		}
	}
	cout << number;
	return 0;
}