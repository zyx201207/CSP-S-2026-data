#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, sum = 0;
int a[200005];
char c[200005];
string l;

string tim(int x, char y) {
	string ans;
	for (int i = 0; i < x; i++) {
		ans = ans + y;
	}
	return ans;
}

bool ups(string s) {
	for (int i = 0; i <= s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) {
			return false;
		}
	}
	return true;
}

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %c", &a[i], &c[i]);
		l = l + tim(a[i], c[i]);
	}
	if (ups(l)) {
		printf("0");
		return 0;
	}
	for (int i = 0; i <= l.length() / 2; i++) {
		if (l[i] != l[l.length() - 1 - i]) {
			sum++;
		}
	}
	printf("%d", sum);
	return 0;
}
