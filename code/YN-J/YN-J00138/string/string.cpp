#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string s = "";
	vector<int>vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
		char b;
		cin >> b;
		s += b;
	}
	ll sum = 0, id = n - 1;;
	for (int i = 0; i < (n + 1) / 2; i++) {
		if (s[i] != s[id]) {
			sum += vec[i];
			if (vec[id] - vec[i] > 0) {
				vec[id] -= vec[i];
			} else {
				s[id] = s[i];
				id--;
			}
		}
	}
	cout << sum;
	return 0;
}