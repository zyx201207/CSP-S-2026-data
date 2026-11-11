#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ll a, c, b1 = 0, d1 = 0;
	string b, d;
	char B, D;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	for (int i = 0; i <= b.size() - 1; i++) {
		if (b[i] >= '0' && b[i] <= '9' && i == 0) {
			b1 += (b[i] - 48) * 10;
		} else if (b[i] >= '0' && b[i] <= '9') {
			b1 += (b[i] - 48);
		} else {
			B = b[i];
		}
	}
	for (int i = 0; i <= d.size() - 1; i++) {
		if (d[i] >= '0' && d[i] <= '9' && i == 0) {
			d1 += (d[i] - 48) * 10;
		} else if (d[i] >= '0' && d[i] <= '9') {
			d1 += (d[i] - 48);
		} else {
			D = d[i];
		}
	}
	if (b1 == d1)
		cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if (max(B, D) == 'E' && min(B, D) == 'D' || max(B, D) == 'C' && min(B, D) == 'B' || max(B, D) == 'C'
	        && min(B, D) == 'A' || max(B, D) == 'B' && min(B, D) == 'A') {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if (max(B, D) - min(B, D) == 1 && max(B, D) != 'D' && min(B, D) != 'C')
		cout << 1;
	else {
		cout << 0;
	}
	return 0;
}