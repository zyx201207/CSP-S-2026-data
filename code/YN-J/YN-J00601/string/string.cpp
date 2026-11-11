#include <bits/stdc++.h>
using namespace std;
long long n;
string s1, s2;
long long ha;
char c;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> ha;
		cin >> c;

		for (int i = 1; i <= ha; i++) {

			s1 += c;
		}
	}

	long long len = s1.size();

	for (int i = 0; i < len; i++) {

		s2[i] = s1[len - i - 1];
	}

	long long sum = 0;

	for (int i = 0; i < len; i++) {

		if (s1[i] != s2[i]) {
			sum++;
		}
	}

	cout << sum / 2;
	return 0;
}