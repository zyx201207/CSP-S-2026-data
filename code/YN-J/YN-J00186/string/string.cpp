#include <bits/stdc++.h>
using namespace std;
string s;
int a[10001], c[10001];
long long o = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[0] == s[i])
			cout << 0;
	}
	return 0;
}