#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("card.in", "r", stdin);
	//freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	vector<int> tong(m);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}
	for (int i = 0; i < n; i++) {
		vector<int> cao(n);
		for (int j = i; j < n; j++) {
			cao[j] = vec[j];
			int flag = 1;
			for (int k = 0; k < j; k++) {
				if (vec[j] == cao[k]) {
					vector<int> cao(n, 0);
					flag = 0;
					break;
				}
			}
			if (!flag) {
				for (int x = 0; x < cao.size(); x++) {
					tong[cao[x]] += 1;
				}
			}
		}
	}
	for (int a = 0; a <= m; a++) {
		if (tong[a] != 0) {
			cout << tong[a] << " ";
		}
	}
	return 0;
}