#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int a, sum = 0;
	for (int i = 1; i <= a; i++) {
		int z;
		char b;
		cin >> z >> b;
		sum = sum + (z / 2);
	}
	cout << sum;
	return 0;
}
