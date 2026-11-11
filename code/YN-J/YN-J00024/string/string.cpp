#include <bits/stdc++.h>
using namespace std;
string s;
string f;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long ans = 0;

	for (int i = 0; i < n; i++) {

		long long a;
		cin >> a;
		char c;
		cin >> c;
		s += a * c;


	}

	for (int i = 0; i < s.size() - 1; i++) {

		f[i] = s[s.size() - i];
	}

	for (int i = s.size(); i > 0 ; i--) {

		if (f[i] != s[i]) {
			
			ans++;
		} else {
			ans += 0;
		}
	}

	cout << ans-1;




	return 0;
}
