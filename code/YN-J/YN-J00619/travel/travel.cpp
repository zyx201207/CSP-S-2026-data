#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n1, n2;
string s1, s2;
bool flag = true;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n1 >> s1 >> n2 >> s2;
	if (n1 == n2) {
		cout << 1;
	} else {
		flag = false;
		cout << 0;
	}
	if (s1[0] * 10 + s1[1] == s2[0] * 10 + s2[1]) {
		cout << (flag ? 1 : 0);
	} else {
		cout << 0;
	}
	if (s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') {
		cout << (flag ? 1 : 0);
	} else {
		cout << 0;
		flag = false;
	}
	if (s1[2] + 1 == s2[2] || s1[2] - 1 == s2[2]) {
		cout  << (flag ? 1 : 0);
	} else {
		cout << 0;
	}
	return 0;
}