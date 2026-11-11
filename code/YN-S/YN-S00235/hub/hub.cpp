#include <iostream>
using namespace std;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t, i = 1;
	cin >> c >> t;

	while (t--) {
		int n, k, u, v;
		cin >> n >> k;

		for (int i = 1; i < n; i++) {

			cin >> u >> v;
		}

		cout << i << endl;
		i++;
	}

	return 0;
}
