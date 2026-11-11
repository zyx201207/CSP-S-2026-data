#include <iostream>

using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t, zm;
		cin >> t >> zm;
		v.push_back(t);
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if ((zm * t) % 2 == 0) {
			for (int j = 0; j < n; j++) {
				if ((v[i] + v[n - 1]) / 2 == v[i]) {
					cout << "0";
				} else {
					sum++;
					cout << sum;
				}
			}
		}
	}
	return 0;
}