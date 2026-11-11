#include <bits/stdc++.h>
using namespace std;
int n;
long long len;
int a[200005];
char c[200005];
string s;
long long ans;

string k(char c, int n) {
	string s1;
	string s2;
	s2 += c;
	while (n != 0) {
		if (n % 2 == 1) {
			s1 += s2;
		}
		n /= 2;
		s2 += s2;
	}
	return s1;

}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		s += k(c[i], a[i]);
		len += a[i];
	}
	int mid = len / 2;
	if (len % 2 == 1) {
		int l = mid - 1, r = mid + 1;
		for (; l >= 0 and r < len;) {
			if (s[l] != s[r]) {
				ans++;
			}
			l--;
			r++;
		}

	} else {
		mid -= 1;
		int l = mid, r = mid + 1;
		for (; l >= 0 and r < len;) {
			if (s[l] != s[r]) {
				ans++;
			}
			l--;
			r++;
		}
	}
	cout << ans;
	return 0;
}