#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 10;

int c, T, n, k;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while(T --) {
		cin >> n >> k;
		cout << (n - k) / 2 << '\n'; 
	}
	return 0;
}

