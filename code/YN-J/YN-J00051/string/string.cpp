#include <bits/stdc++.h>
using namespace std;


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	string b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cin >> b[i];
	}
	string s = "";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			s += b[i];
		}
	}
	int l = s.size();
	int cnt;
	for (int i = 0; i < l ; i++) {

		if (s[i] != s[l - 1 - i]) {

			cnt++;

		}
	}
	cout << cnt / 2;



	return 0;

}