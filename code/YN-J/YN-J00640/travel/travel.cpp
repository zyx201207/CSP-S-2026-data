#include <bits/stdc++.h>
using namespace std;
int main() {
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	int a, b;
	char c, d;
	cin >> a >> b >> c >> d;

	if (a == c) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (c == d && a == c) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (c == d && a == c) {
		cout << "1";
	} else {
		cout << "0";
	}

	if (a == c && c == d && c + 1 == d) {
		cout << "1";
	} else {
		cout << "0";
	}

	return 0;
}