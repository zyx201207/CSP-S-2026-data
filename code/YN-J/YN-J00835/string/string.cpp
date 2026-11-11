#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long cnt = 0;
	string s;

	for (int i = 0; i < n; i ++) {

		int a;
		char b;
		cin >> a >> b;

		for (long long i = cnt; i < a + cnt; i ++)

			s.push_back(b);
		cnt += a;
	}

	long long ans = 0;

	for (long long i = 0; i < s.size() / 2; i ++)

		if (s[i] != s[s.size() - 1 - i])
			ans ++;
	cout << ans;
	return 0;
}