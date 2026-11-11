#include <bits/stdc++.h>
using namespace std;
long long a[1000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		for (int i = 1; i <= s.size(); i++) {
			for (int j = 1; j <= s.size(); j++) {
				cin >> a[i] >> a[j];
				int p = s[i] + a[j] ;
				cout << p;
				return 0;
			}
		}
	}
	return 0;
}