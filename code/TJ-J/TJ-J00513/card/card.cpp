#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> ans(m + 1, 0);
	for (int i = 0; i < n; i++) {
		vector<int> k;
		for (int j = i; j < n; j++) {
			int p = -1;
			for (int x = 0; x < k.size(); x++) {
				if (k[x] == a[j]) {
					p = x;
					break;
				}
			}
			if (p == -1) {
				k.push_back(a[j]);
			}
			else {
				while (k.size() != p) k.pop_back();
				k.push_back(a[j]);
			}
		}
		for (int j = 0; j < k.size(); j++) {
			ans[k[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
