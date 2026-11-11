#include <bits/stdc++.h>
using namespace std;
int n;
int a;
char c;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> c;
		for (int j = 0; j < a; j++)
			s += c;
	}
	int mi = 0;
	for (int i = 0, j = s.size() - 1; i < (s.size() + 1) / 2, j >= i; i++, j--) {
		if (s[i] != s[j])
			mi++;
	}
	cout << mi;
	return 0;
}

