#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pir;
const int maxn = 2e6 + 5;

void solve() {
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 != c2) {
		cout << "0000\n";
	} else {
		int temp1 = 0, temp2 = 0;
		temp1 += (s1[1] - '0');
		temp1 += (s1[0] - '0') * 10;
		temp2 += (s2[1] - '0');
		temp2 += (s2[0] - '0') * 10;
		if (temp1 != temp2) {
			cout << "1000\n";
		} else {
			if (!((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s1[2] >= 'D'))) {
				cout << "1100\n";
			} else {
				if (abs(s1[2] - s2[2]) > 1) {
					cout << "1110\n";
				} else {
					cout << "1111\n";
				}
			}
		}
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	solve();
	return 0;
}