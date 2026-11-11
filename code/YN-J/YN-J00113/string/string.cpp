#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

int main() {
	freopen(" string.in", "r", stdin);
	freopen(" string.out", "w", stdout);
	int n;
	cin >> n;
	string s = " ";
	vector<int >vec(n) ;
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		char b;
		cin >> b;
		s +=  b;
	}
	ll sum = 0, max = 0;

	string s1 = " ";
	for (int i = 0; i < n; i++) {
		max += vec[i];
		for (int j = 0; j < vec[i]; j++) {
			s1 += s[i];
		}
	}
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	if (s1 == s2) {
		cout << sum;
		return 0;
	} else {
		for (int i = 0; i < (max + 1) / 2; i++) {
			if (s[i] != s[max - i - 1]) {
				s[n - i - 1] = s[i];

				sum ++;
			}

		}
	}
	cout << sum;
	return 0;
}
