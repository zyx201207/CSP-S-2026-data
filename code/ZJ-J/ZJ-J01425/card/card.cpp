#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 3;
int n, m, bottle[N], a[N];
set<int> s;

bool find(int x) {
	for (auto i : s) {
		if (x == i) return true;
	}
	return false;
}

int main() {
	freopen("card4.in", "r", stdin);
	freopen("card4.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = k; i <= n; i++) {
			int x = a[i];
			
			if (find(x)) {
				s.clear();
				s.insert(x);
			} else {
				s.insert(x);
			}
		}
		for (auto i : s) {
			bottle[i]++;
		}
		s.clear();
	}
	
	for (int i = 1; i <= m; i++) {
		if (i > 1) cout << ' ';
		cout << bottle[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
