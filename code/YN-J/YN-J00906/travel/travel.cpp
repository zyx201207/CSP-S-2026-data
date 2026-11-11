#include <bits/stdc++.h>
using namespace std;

string tr1, tr2, zw1, zw2;

int num(char a) {
	if (a >= 'A' && a <= 'C') {
		return 1;
	} else {
		return 2;
	}
}

bool check(char a, char b) {
	if ((a == 'D' && b == 'F') || (a == 'F' && b == 'D'))
		return true;
	else if (num(a) == num(b) && abs(a - b) == 1)
		return true;

	return false;
}

void solve() {
	cin >> tr1 >> zw1 >> tr2 >> zw2;

	if (tr1 == tr2) {
		cout << 1;
	} else {
		cout << 0;
	}

	char a = zw1[2], b = zw2[2];

	zw1.erase(2, 1);
	zw2.erase(2, 1);

	if (tr1 == tr2 && zw1 == zw2) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (tr1 == tr2 && zw1 == zw2 && num(a) == num(b)) {
		cout << 1;
	} else {
		cout << 0;
	}

	if (tr1 == tr2 && zw1 == zw2 && num(a) == num(b) && check(a, b)) {
		cout << 1;
	} else {
		cout << 0;
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
}