#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[1005];
	char c[1005];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i + 1; j++) {
			cin >> a[i] >> c[i];
		}
	}

	return 0;
}
