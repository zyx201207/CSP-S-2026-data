#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> lst;
	lst.clear();
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		lst.push_back(x);
	}

	int ans = 0;
	if (m == 2) {
		for (int i = 0; i < lst.size(); i++) {
			for (int j = 0; j < lst.size(); j++) {
				if (i == j)
					continue;
				if (lst[i]&lst[j] > ans) {
					ans = lst[i] & lst[j];
				}
			}
		}
	} else if (m == 3) {
		for (int i = 0; i < lst.size(); i++) {
			for (int j = 0; j < lst.size(); j++) {
				for (int k = 0; k < lst.size(); k++) {
					if (i == j || i == k || j == k)
						continue;
					if (lst[i]&lst[j]&lst[k] > ans) {
						ans = lst[i] & lst[j] & lst[k];
					}
				}
			}
		}
	} else if (m == n) {
		ans = lst[0];
		for (int i = 1; i < lst.size(); i++) {
			ans = lst[i] & ans;
		}
	}

	cout << ans;

	return 0;
}