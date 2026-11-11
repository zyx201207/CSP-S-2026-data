#include <bits/stdc++.h>
using namespace std;

struct node {
	char ch;
	int pl;
} a[200005];
int n;
unsigned long long ans = 0;
string s, s1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char ch;
		int pl;
		cin >> pl >> ch;
		for (int j = 1; j <= pl; j++) {
			s += ch;
		}
	}
	s1 = s;
	reverse(s.begin(), s.end());
	unsigned long long ans = 0;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s1[i] != s[i]) {
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}
