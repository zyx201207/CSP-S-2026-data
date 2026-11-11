#include <bits/stdc++.h>
using namespace std;
string s, s1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, ans = 0, sum1 = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a;
		int a1;
		cin >> a1 >> a;
		for (int i = 0; i < a1; i++) {
			s[ans] = a;
			ans++;
		}
	}
	bool f = true;
	for (int i = 0; i < s.size(); i++) {
		s1[i] = s[s.size() - 1 - i];
		if (s[i] != s[0]) {
			f == false;
			sum1++;
		}
	}
	if (f) {
		cout << "0";
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s1[i] != s[i]) {
			sum++;
		}
	}
	cout << min(sum, sum1);
	return 0;
}