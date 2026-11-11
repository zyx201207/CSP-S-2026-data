#include<bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long n, ans, k, c, t;
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		if(c == 7 || c == 11 || c == 12) {
			cout << 1 << "\n";
			continue;
		}
		cin >> n >> k;
		long long q = (n - 1) / 2 - 1;
		cout << floor(q / 3) + 1 << "\n";
	}
	return 0;
}