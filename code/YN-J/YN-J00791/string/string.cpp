#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];
string s, s1;
int n;
int m;
int ans = 0;

string reverse(string s2) {
	string t1;
	int length = s2.size();
	for (int i = length - 1; i >= 0; i--) {
		t1 += s[i];
	}
	s2 = t1;
	return s2;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}
	m = s.size();
	s1 = reverse(s);
	for (int i = 0; i < m / 2; i++) {
		if (s1[i] != s[i]) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}

