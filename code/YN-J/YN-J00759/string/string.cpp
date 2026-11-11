#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];

int hwc(string s) {
	string bj = "";
	for (int i = s.size() - 1; i >= 0; i--) {
		bj = bj + s[i];
	}
	if (bj == s) {
		return 1;
	} else {
		return 0;
	}
}

string sw(string s1) {
	string zh = "";
	for (int i = s1.size() - 1; i >= 0; i--) {
		zh = zh + s1[i];
	}
	return zh;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0;
	string s = "";
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			s = s + c[i];
		}
	}
	string s1 = s.substr(0, s.size() / 2);
	string s2 = sw(s1);
	string s3 = s.substr(s.size() / 2 + 1, s.size() - 1);
	//cout << s;
	//cout << s1 << endl;
	//cout << s2 << endl;
	for (int i = 0; i <= s1.size() - 1; i++) {
		if (s2[i] != s3[i]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}