#include <bits/stdc++.h>
using namespace std;

struct s {
	long long a1;
	char c1;
};
s s1[1000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long sum = 0, n;
	cin >> n;
	string S, S1;

	for (long long i = 0; i < n; i++) {
		cin >> s1[i].a1 >> s1[i].c1;
	}
	for (long long i = 0; i < n; i++) {
		for (long long j = 1; j <= s1[i].a1; j++) {
			S = S + s1[i].c1;
		}
	}

	for (long long i = S.length() - 1; i >= 0; i--) {
		S1 = S1 + S[i];
	}
	for (long long i = 0; i < n; i++) {
		if (S1[i] != S[i]) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}