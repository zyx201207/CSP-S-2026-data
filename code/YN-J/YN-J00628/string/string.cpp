#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string s = "";
	long long n;
	cin >> n;
	while (n--) {
		long long a;
		char c;
		cin >> a >> c;
		for (long long i = 1; i <= a; i++) {
			s += c;
		}
	}
	string s2 = s;
	long long a = s.size(), sum = 0, cnt = 0;
	for (long long i = 0; i < a / 2; i++) {
		if (s[i] != s2[a - i - 1])
			sum++;
		i++;
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}