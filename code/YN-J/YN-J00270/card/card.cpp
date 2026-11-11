#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N];
int vis[N];
vector<int> table;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int x = 0; x <= sizeof(table); x++) {
				if (table[x] == a[j]) {
					for (int y = x; y < table.size(); y++) {
						table[y] = 0;
					}
					continue;
				}
			}
			table[j + 1] = a[j];
		}
		for (int j = i; j <= n; j++) {
			vis[table[j]]++;
		}
	}
	for (int i = 0; i < sizeof(vis); i++) {
		cout << vis[i] << " ";
	}

	return 0;
}