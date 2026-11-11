#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5;
string s;
int cnt;
char ch;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cnt >> ch;
		while (cnt--) s += ch;
	}
	int res = 0;
	for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
		if (s[i] != s[j])
			res++;
	}
	cout << res << endl;
	return 0;
}
