#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int cnt = 0;
string s1, s2;
int l = 0;
int m = 0;
bool f = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		l += a[i];
	}
	for (int i = 1; i <= n; i++) {
		s1 += a[i] * c[i];
	}
	for (int i = l; i >= 0; i--) {
		cnt++;
		s2 += s1[i];
		s2[i] = s2[l] + 1 - i;
		if (s2[i] == s1[i]) {
			f = 1;
			break;
		}
	}
	if (f == 1) {
		cout << cnt;
	}
	return 0;
}