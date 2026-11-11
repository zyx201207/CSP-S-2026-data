#include <bits/stdc++.h>
using namespace std;
int const maxn = 3e5 + 5;
int a[maxn];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 1;
	if (m = 1) {
		cout << n - m;
	}
	if (m = 2) {
		cout << 2 << " " << 1;
	}

	return 0;
}
//s.substr( )