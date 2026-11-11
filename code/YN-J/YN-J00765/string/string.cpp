#include <bits/stdc++.h>
using namespace std;
string s;

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n ; i++ ) {
		int cs;
		string z;
		cin >> cs >> z;
		for (int j = 0; j < cs; j++) {
			s += z;
		}
	}
	int r = s.size();
	int b = r / 2;
	string s1, s2;
	for (int i = 0; i < b; i++) {
		s1 += s[i];
	}
	for (int i = b; i < r; i++) {
		s2 += s[i];
	}
	int cnt = 0;
	for (int i = 0; i < b; i++) {
		if (s1[i] != s2[i])
			cnt++;
	}
	cout << cnt;
	return 0;
}
