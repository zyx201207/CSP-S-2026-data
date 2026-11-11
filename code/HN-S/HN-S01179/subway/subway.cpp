#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c, n, m, d, p;
int main() {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> p;
	srand(time(0));
	while (p--) {
		int num = rand();
		cout << num << '\n';
	}
	return 0;
} 
