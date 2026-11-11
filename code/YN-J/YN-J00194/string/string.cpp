#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	string s = "";
	map<char, int> M;
	long long m_s = 0;
	char m_c;
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		M[c]
		+= a;
		while (a--)
			s += c;
	}
	long long m = s.size() / 2;
	long long ans = 0;
	if (s.size() % 2 == 0) {
		M[s[m]]
		--;
		M[s[m - 1]]--;
		if (s[m] != s[m - 1])
			ans++;
	} else {
		M[s[m]]--;
	}
	for (auto x : M) {
		if (x.second > m_s) {
			m_s = x.second;
			m_c = x.first;
		}
	}
	ans += s.size() % 2 == 0 ? (s.size() - 2) - m_s : (s.size() - 1) - m_s;
	cout << ans;
	return 0;
}