#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int t;
	cin >> t;
	string s;
	for (int i = 0; i < t; i++) {
		int a;
		char c;
		cin >> a >> c;
		for (int i = 0; i < a; i++) {
			s += c;
		} 
	}
	int n = s.size();
	if (n == 1) {
		cout << 0;
		return 0;
	}
	int mid = (n / 2);
	string s1, s2;
	for (int i = 0; i < mid; i++) {
		s1 += s[i];
	}
	for (int i = mid+1; i < n; i++) {
		s2 += s[i]; 
	}
	int ans = 0;
	for (int i = 0; i < mid; i++) {
		if (s1[i] != s2[i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
} 
