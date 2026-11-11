#include <bits/stdc++.h>
using namespace std;

long long n, x;
set <int> s;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		s.insert(x);
	}
	
	for (int i = 1; i <= s.size(); ++i) {
		cout << 0 << ' ';
	}
	return 0;
}
