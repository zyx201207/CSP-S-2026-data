#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N];

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1, cmp);
	int mx = 1;
	int i = 0, j = 0, cnt;
	long long xly;

	while (true) {
		xly = 0;
		i++;
		cnt = 1;

		while (a[i + 1] == a[i]) {
			cnt++;
			i++;

			if (i == n) {
				mx = max(cnt, mx);
				break;
			}
		}

		j = i;

		while (xly <= m) {
			j++;
			xly += a[i] - a[j];

			if (xly <= m) {
				cnt++;
			} else {
				break;
			}
		}

		mx = max(cnt, mx);

		if (mx >= n - i) {
			break;
		}
	}

	cout << mx;
	return 0;
}
