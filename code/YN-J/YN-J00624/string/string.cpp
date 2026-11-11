#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N];
char c[N];
string s;


int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n, b = 0, d = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		b = a[i] + b;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			s += c[i];
		}
	}
	for (int i = 0; i < b / 2; i++) {
		if (s[i] != s[b - i - 1]) {
			d++;
		}
	}
	cout << d;
	return 0;
}