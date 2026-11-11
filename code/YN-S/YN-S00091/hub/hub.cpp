#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c, t;
	cin >> c >> t;
	srand(time(0));

	while (t--) {
		cout << rand() % 20 << "\n";
	}
}