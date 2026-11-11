#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", "stdin");
	freopen("string.out", "w", "stdout");
	string s = "";
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		string s1;
		cin >> s1;
		for (int i = 1; i <= x; ++i) {
			s += s1;
		}
	}
	int it1 = 0, it2 = s.size() - 1;
	for (int i = 1; i <= s.size(); ++i) {
		if (s[it1] != s[it2]) {
			++ans;
		}
		it1++;
		it2--;
		if (it1 == it2) {
			break;
		}
	}
	cout << ans;
	return 0;
}