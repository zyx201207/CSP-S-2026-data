#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
	ll c1, c2;
	string s1, s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	if (c1 == c2) {
		if (s1.substr(0, 2) == s2.substr(0, 2)) {
			if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')) {
				if ((s1[2] + 1 == s2[2] && (s1[2] != 'C' && s2[2] != 'D')) || (s2[2] + 1 == s1[2] && (s1[2] != 'D' && s2[2] != 'C')) || ((s1[2] == 'D' && s2[2] == 'F') || (s2[2] == 'D' && s1[2] == 'F'))) {
					cout << "1111\n";
				} else {
					cout << "1110\n";
				}
			} else {
				cout << "1100\n";
			}
		} else {
			cout << "1000\n";
		}
	} else {
		cout << "0000\n";
	}
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	ll T = 1;
	while (T --) solve();
	return 0;
}