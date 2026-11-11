#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int a;
char s1;
long long lens = s.size();
int sum = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> s1;
		for (int j = 1; j <= a; j++) {
			s += s1;
		}
	}
	for (int i = 0, j = lens - 1; i <= j; i++, j--) {
		if (s[i] != s[j]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}