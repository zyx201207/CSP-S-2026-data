#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1, s1, c2, s2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	int paishu1 = (s1[0] - '0') * 10 + (s1[1] - '0') * 1;
	int paishu2 = (s2[0] - '0') * 10 + (s2[1] - '0') * 1;
	if (c1 == c2 && paishu1 != paishu2) {
		cout << "1000";
		return 0;
	}
	char zuowei1 = s1[2];
	char zuowei2 = s2[2];
	bool zw1 = 0;
	bool zw2 = 0;
	if (zuowei1 == 'A' || zuowei1 == 'B' || zuowei1 == 'C') {
		zw1 = 1;
	}
	if (zuowei2 == 'A' || zuowei2 == 'B' || zuowei2 == 'C') {
		zw2 = 1;
	}
	if (c1 == c2 && paishu1 == paishu2 && zw1 != zw2) {
		cout << "1100";
		return 0;
	}
	int paicha = abs(paishu1 - paishu2);
	int haocha = abs((int)zuowei1 - (int)zuowei2);
	if ((zw1 == 1 && zw2 == 1) || (paicha == 0 && haocha == 1)) {
		cout << "1111";
		return 0;
	}
	if ((zw1 == 0 && zw2 == 0) || (paicha == 0 && haocha == 2)) {
		cout << "1111";
		return 0;
	}
	cout << "1110";
	return 0;
}
