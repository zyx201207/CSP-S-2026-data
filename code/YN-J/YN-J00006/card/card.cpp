#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[500010], b[200005];
	vector<int> v;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[j] == a[i]) {
				v.clear();
			}
		}
		v.push_back(a[i]);
		for (int j = 0; j < v.size(); j++) {
			b[j]++;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << b[i] << ' ';
	}
	return 0;
}