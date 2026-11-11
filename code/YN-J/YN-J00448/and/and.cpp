#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e2 + 2;
int a[MAXN];

int main() {
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (m == 1) {
		ans = max(a[n], a[n - 1]);
	}

	if (ans > 0) {
		cout << ans;
	} else {
		cout << 0;
	}
	return 0;
}


