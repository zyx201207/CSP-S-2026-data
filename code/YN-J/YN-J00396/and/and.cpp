#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
ll n, m, cnt, w[N];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	sort(w + 1, w + n + 1);
	if (m == 1) {
		cout << w[n];
		return 0;
	}
	int flag = 0, vis = 30;
	for (int i = n; i >= 1; i--) {
		if (flag == 2)
			break;
		if (cnt == m && flag == 1) {
			cout << w[i - m + 1];
			return 0;
		}
		int tmp = cnt;
		for (int j = 1; j <= vis; j++) {
			if ((1 << j) == w[i]) {
				cnt++, vis = j;
				if (i == n)
					flag = 1;
				break;
			}
		}
		if (cnt == tmp)
			flag = 2;
	}
	cout << w[n - m + 1];
	return 0;
}
