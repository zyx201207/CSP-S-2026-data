#include <bits/stdc++.h>
using namespace std;
int n;
struct dd {
	long long a;
	char c;
} m[200010];
int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i].a >> m[i].c;
	}
	int idx = 0, id = n - 1;
	while (idx < id) {
		if (m[idx].a >= m[id].a) {
			if (m[idx].c != m[id].c) {
				ans += m[id].a;
			}
			m[idx].a -= m[id].a;
			id--;
		} else {
			if (m[idx].c != m[id].c) {
				ans += m[idx].a;
			}
			m[id].a -= m[idx].a;
			idx++;
		}
	}
	cout << ans;
	return 0;
}
