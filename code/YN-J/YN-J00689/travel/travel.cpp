#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	bool ca, cb, sa, sb;
	cin >> ca >> sa >> cb >> sb;
	if (ca = cb) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (sa = sb) {
		cout << "1";
	} else {
		cout << "0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}