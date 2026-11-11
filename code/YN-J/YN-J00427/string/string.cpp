#include <bits/stdc++.h>
using namespace std;
int n, a, sum;
char c;
string s[1000000], s1[100000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long t = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		for (int j = 1; j <= a; j++) {
			s[t] = c;
			t++;
		}
	}
	long long t1 = 0;
	for (int i = t - 1; i >= 0; i--) {
		s1[t1] = s[i];
		t1++;
	}
	for (int i = 0; i <= t - 1; i++) {
		if (s[i] != s1[i]) {
			sum++;
		}
	}
	cout << sum / 2 ;
	return 0;
}