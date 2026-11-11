#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x, cnt;
char c;
string s;

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdin);
	cin >> n;
	while (n--) {
		cin >> x >> c;
		while (x--)
			s += c;
	}
	string a = s;
	reverse(s.begin(), s.end());
	for (int i = 0; i <= (s.size()) / 2; i++)
		if (s[i] != a[i])
			cnt++;
	cout << cnt;
	return 0;
}