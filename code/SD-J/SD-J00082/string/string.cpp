#include <bits/stdc++.h>
#define ll long long
#define N 300010
#define INF 1e9
using namespace std;
string s;
int n, a[N], ans;
char c[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	s += ' ';
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; ++j) {
			s += c[i];
		}
	}
	int l = (int)s.size() - 1;
	for (int i = 1; 2 * i <= 1 + l; ++i) {
		if (s[i] != s[l - i + 1]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}
