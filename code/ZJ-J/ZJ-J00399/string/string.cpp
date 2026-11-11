#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, ans;
vector<char>s;
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	s.push_back('?');
	for (int i = 1; i <= n; i++) {
		int a;
		char c;
		cin >> a >> c;
		while (a--)s.push_back(c);
	}
	n = s.size() - 1;
	for (int i = 1; i <= n / 2; i++)
		if (s[i] != s[n - i + 1])ans++;
	cout << ans <<'\n';
	return 0;
}
