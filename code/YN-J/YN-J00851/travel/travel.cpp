#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	string a1, a2;
	cin >> a >> a1 >> b >> a2;
	if (a != b) {
		cout << "0000";
		return 0;
	}
	cout << "1";
	int sum1, sum2;
	sum1 = (a1[0] - '0') * 10 + (a1[1] - '0');
	sum2 = (a2[0] - '0') * 10 + (a2[1] - '0');
	if (sum1 != sum2) {
		cout << "000";
		return 0;
	}
	cout << "1";
	if (a1[2] >= 'D' && a2[2] >= 'D') {
		cout << "1";
	} else if (a1[2] <= 'C' && a2[2] <= 'C') {
		cout << "1";
	} else {
		cout << "00";
		return 0;
	}
	if (abs(a1[2] - a2[2]) == 1) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}