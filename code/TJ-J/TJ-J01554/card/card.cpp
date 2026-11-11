#include <bits\stdc++.h>
using namespace std;

int main() {

	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m, bo = 0;
	cin >> n >> m;
	int cards[n], type[m], ty = -1, type1[m], co[m];
	memset(type, 0, sizeof(type));
	memset(type1, 0, sizeof(type1));
	memset(co, 0, sizeof(co));
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
		for (int j = 0; j < m; j++) {
			if (type[j] == cards[i])
				bo = 1;
		}
		if (!bo) {
			type[ty++] = cards[i];
		}
	}
	queue <int>table;
	queue <int>table2;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (type[k] == cards[j])
					type1[k]++;
				if (type1[k] == 2) {
					while (!table.empty()) {
						if (table.front() == type[k]) {
							table2.push(table.front());
							while (!table.empty()) {
								table.pop();
							}
						} else {
							table2.push(table.front());
							table.pop();
						}
					}
					while (!table2.empty()) {
						table.push(table2.front());
						table2.pop();
					}
					type1[k] = 1;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			if (type1[i] >= 1 ) {
				co[i]++;
			}
		}
		memset(type1, 0, sizeof(type1));
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (type[i] > type[j]) {
				swap(type[i], type[j]);
				swap(co[i], co[j]);
			}
		}
	}
	for (int i = 0; i < m - 1; i++) {
		if (i > 0)
			co[i]--;
		cout << co[i] << " " ;
	}
	cout << co[m - 1];
	return 0;
}