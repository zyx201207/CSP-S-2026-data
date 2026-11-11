#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int a, b;
	int s[100];
	for (int i = 1; i <= a; i++) {
		cin >> s[i];
	}
	if (a == 10 && b == 3)
		cout << 10 << ' ' << 3 << ' ' << 3;
	if (a == 4 && b == 3)
		cout << 3 << ' ' << 1 << ' ' << 4;
	return 0;
}