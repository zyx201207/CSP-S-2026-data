#include <bits/stdc++.h>
using namespace std;
string s;
int n, loc = 1, sum, len;

int find(int l, int r) {
	if (l == r && len % 2 == 0)
		return 0;
	if (len % 2 == 1) {
		if (r - l == 1) {
			return 0;
		}
	}
	if (s[l] == s[r])
		return find(l + 1, r - 1);
	else
		return r;
}

void kill(int l, int r) {
	int l1, r1, df = find(1, len);
	sum++;
	s[df] = s[len - df + 1];
	df = find(1, len);
	if (!df) {
		return;
	}
	kill(len - df + 1, df);
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, c;
		char b;
		cin >> a >> b;
		len += a;
		for (int i = 1; i <= a; i++) {
			s += b;
		}
	}
	if (!find(1, len)) {
		cout << 0;
		return 0;
	} else {
		kill(len - find(1, len) + 1, find(1, len));
		cout << sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}