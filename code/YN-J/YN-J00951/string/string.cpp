#include <bits/stdc++.h>
using namespace std;

struct node {
	char a;
	long long c;
} s[200005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	string s;
	for (long long i = 1; i <= n; i++) {
		long long a;
		char b;
		cin >> a >> b;
		for (long long j = 1; j <= a; j++) {
			s += b;
		}
	}
	long long sum = 0;
	for (long long i = 1; i <= s.size() / 2; i++) {
		if (s[i] != s[s.size() + 1 - i]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}