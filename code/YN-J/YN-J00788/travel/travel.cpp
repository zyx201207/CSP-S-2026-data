#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "w", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int sum = 0;
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}

	for (int i = 0; i < 2; i++) {
		if (s1[i] == s2[i])
			sum++;
	}
	if (sum == 2) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	int n = s1.size();
	if (('D' <= s1[n - 1] && s1[n - 1] <= 'F') && ('D' <= s2[n - 1] && s2[n - 1] <= 'F')) {
		cout << "11";
		return 0;
	}
	if (('A' <= s1[n - 1] && s1[n - 1] <= 'C') && ('A' <= s2[n - 1] && s2[n - 1] <= 'C')) {
		cout << 1;
		if ((abs(s1[n - 1] - s2[n - 1]) == 1)) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << "00";
		return 0;
	}

	return 0;
}