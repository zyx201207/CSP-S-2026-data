#include <bits/stdc++.h>
using namespace std;
long long a[200005];

int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	long long maxn = 0, minn = 0x3f3f3f3f;
	cin >> a[0];
	maxn = max(maxn, a[0]);
	int s = a[0];
	minn = min(minn, a[0]);
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		s &= a[i];
		minn = min(minn, a[i]);
		maxn = max(maxn, a[i]);
	}

	if (m == 1) {
		cout << maxn;
	} else if (m == n) {
		cout << s;
	} else if (maxn < 4) {
		cout << "2";
	} else {
		cout << minn;
	}



	return 0;
	fclose(stdin);
	fclose(stdout);
}
