#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n;

string s = "";

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		string t(a, c);
		s += t;
	}
	
	int l = 0, r = s.size() - 1, res = 0;
	while (l < r) {
		if (s[l] != s[r])
			res++;
		l++, r--;
	}
	cout << res;
	return 0;
}