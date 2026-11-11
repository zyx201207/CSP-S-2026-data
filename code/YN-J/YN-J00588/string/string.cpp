#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin)
	freopen("string.out", "w", stdout)
	string n, i, p, sl = 0;
	cin >> n;

	for (i = 1; i <= n; i++) {

		cin >> i + 1;
	}

	p = i*"a" + i*"b" + i*"c";

	if (p == "b")
		sl += 1;

	if (p == "c")
		sl += 1;
	cout << sl;

