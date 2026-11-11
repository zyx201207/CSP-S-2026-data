#include <bits/stdc++.h>
//#define int long long
using namespace std;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	bool f1 = 0, f2 = 0, f3 = 0;
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {//同一车厢
		cout << "1";
		f1 = 1;
	} else {
		cout << "0";
	}
	string s1s, s2s;
	char s1m, s2m;
	for (int i = 0; i <= s1.size() - 1; i++) {//取数子，字母
		if (s1[i] >= '0' && s1[i] <= '9') {
			s1s += s1[i];
		}
		if (isalpha(s1[i])) {
			s1m = s1[i];
		}
		if (s2[i] >= '0' && s2[i] <= '9') {
			s2s += s2[i];
		}
		if (isalpha(s2[i])) {
			s2m = s2[i];
		}
	}
//	cout << "\n" << "s1m:" << s1m << "\n" << "s2m:" << s2m << "\n";
//	cout << "s1s:" << s1s << "\n" << "s2s:" << s2s << "\n";
	if (s1s == s2s && f1 == 1) {//同一车厢，同一排
		cout << "1";
		f2 = 1;
	} else {
		cout << "0";
	}
	//同一车厢，同一排，同一侧
	if (s1m == 'D' && s2m == 'F' && f2 == 1 && f1 == 1) {
		cout << "1";
		f3 = 1;
	} else if (s1m == 'F' && s2m == 'D' && f2 == 1 && f1 == 1) {
		cout << "1";
		f3 = 1;
	} else if (s1m == 'A' && s2m == 'B' && f2 == 1 && f1 == 1) {
		cout << "1";
		f3 = 1;
	} else if (s1m == 'A' && s2m == 'C' && f2 == 1 && f1 == 1) {
		cout << "1";
		f3 = 1;
	} else if (s1m == 'B' && s2m == 'A' && f2 == 1 && f1 == 1) {
		cout << "1";
		f3 = 1;
	} else if (s1m == 'B' && s2m == 'C' && f2 == 1 && f1 == 1) {
		cout << "1";
		f3 = 1;
	} else if (s1m == 'C' && s2m == 'A' && f2 == 1 && f1 == 1) {
		cout << "1";
		f3 = 1;
	} else if (s1m == 'C' && s2m == 'B' && f2 == 1 && f1 == 1) {
		cout << "1";
		f3 = 1;
	} else {
		cout << "0";
	}
	int cc = abs(s1m - s2m);
	if (s1m == 'D' && s2m == 'F' && f2 == 1 && f1 == 1) {
		cc--;
	} else if (s1m == 'F' && s2m == 'D' && f2 == 1 && f1 == 1) {
		cc--;
	}
//	cout << "\n" << "cc:" << cc << "\n";
	//相邻
	if (cc == 1 && f3 == 1 && f2 == 1 && f1 == 1) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}