#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c, t;
int main() {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	srand(time(0));
	while (t--) {
		int num = rand();
		cout << num << '\n';
	}
	return 0;
} 
