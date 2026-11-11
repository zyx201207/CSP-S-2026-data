#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s;
	int x;
	char cc;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cin >> cc;
		for (int j = 0; j < x; j++)
			s += cc;
	}
	string s1;
	int len = s.size();
	for (int i = len - 1; i >= 0; i--)
		s1 += s[i];
	int cnt = 0;
	for (int i = 0; i < len; i++)
		if (s1[i] != s[i])
			cnt++;
	cout << cnt / 2;

	return 0;
}
