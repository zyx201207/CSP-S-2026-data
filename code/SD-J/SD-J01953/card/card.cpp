#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500010];
int b[300010];
int main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	if (n <= 500) {
		for (int i = 0; i < n; i++) {
			vector <int> v;
			for (int j = i; j < n; j++) {
				int id = v.size();
				for (int k = 0; k < v.size(); k++) {
					if (a[j] == v[k]) {
						id = k;
						break;
					}
				}
				id = v.size() - id;
				while (id > 0 && v.size()) {
					v.pop_back();
					id--;
				}
				v.push_back(a[j]);
			}
			for (int j = 0; j < v.size(); j++) {
				b[v[j]]++;
				//cout << v[j] << " ";
			}
			//cout << endl;
		}
		for (int i = 1; i < m; i++) {
			cout << b[i] << " ";
		}
		cout << b[m];
	} else {
		for (int i = 1; i < m; i++) {
			cout << 1;
		}
		cout << 1;
	}
	return 0;
}
