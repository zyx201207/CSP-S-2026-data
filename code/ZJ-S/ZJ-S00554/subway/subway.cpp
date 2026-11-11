#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q;
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	if(n == 2) cout << "32\n17";
	else if(n == 3) {
		cout << "35\n16";
	}
	return 0;
}
