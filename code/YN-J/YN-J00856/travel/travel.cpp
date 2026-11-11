#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, c;
	string b, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (b == d) {
		cout << "111";
	} else {
		cout << "000";
	}



	return 0;
}