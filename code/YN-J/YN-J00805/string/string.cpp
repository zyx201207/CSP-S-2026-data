#include <bits/stdc++.h>
using namespace std;
int a[1000000];
char b[1000000];
int n;
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			s = s + b[i];
		}
	}
	long long num = 0;
	int l = 0, r = n - 1;
	while (l < n) {
		if (s[l] != s[r]) {
			num++;
		}
		l++;
		r--;
	}
	cout << num;
	return 0;
}