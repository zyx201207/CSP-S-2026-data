#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1, s2, c1, c2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	bool f1 = true, f2 = true;
	for (int i = 0; i < c1.size(); i++) {
		if (c1[i] != c2[i])
			f1 = false;
	}
	if (f1)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	for (int i = 0; i < 2; i++) {
		if (s1[i] != s2[i])
			f2 = false;
	}
	if (f2)
		cout << 1;
	else {
		cout << "000";
		return 0;
	}
	if (s1[2] <= 'C' && s2[2] <= 'C')
		cout << 1;
	else if (s1[2] > 'C' && s2[2] > 'C')
		cout << 1;
	else {
		cout << "00";
		return 0;
	}
	int t = int(s1[2] - 'A');
	int f = int(s2[2] - 'A');
	if (t + 1 == f || t - 1 == f) {
		cout << 1;
	} else
		cout << 0;
	return 0;
}