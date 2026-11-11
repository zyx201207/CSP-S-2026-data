#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string sa, ca, sx, cx;
	cin >> sa >> ca >> sx >> cx;
	if (sa == sx) {
		cout << 1;
		if (ca[0] == cx[0] && ca[1] == cx[1]) {
			cout << 1;
			if (ca[2] <= 'C' && ca[2] >= 'A' && cx[2] <= 'C' && cx[2] >= 'A') {
				cout << 1;
				if (ca[2] + 1 == cx[2] || ca[2] - 1 == cx[2]) {
					cout << 1;
				} else
					cout << 0;
			} else if (ca[2] >= 'D' && ca[2] <= 'F' && cx[2] <= 'F' && cx[2] >= 'D') {
				cout << 1 << 1;
			} else
				cout << 0 << 0;
		} else
			cout << 0 << 0 << 0;
	} else
		cout << 0 << 0 << 0 << 0;
	return 0;
}