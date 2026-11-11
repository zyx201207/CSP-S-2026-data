#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 1;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
	} 
	srand(time(0));
	for (int i = 1;i <= n;i++) {
		srand(rand());
		cout << (rand() + m - 1) % m << " ";
	}
	return 0;
}
