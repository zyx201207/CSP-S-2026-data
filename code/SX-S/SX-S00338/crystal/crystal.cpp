#include <bits/stdc++.h>
using namespace std;
int n, m;
long long zjh[500005];
int zjh2[500005];
int cnt = 1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> zjh[i];
	}
	sort(zjh, zjh + n);
	for (int i = 1; i <= n; i++) {
		if (zjh[1] < 0)
			zjh2[1] = -zjh[1];
		else
			zjh2[i] = zjh[i] - zjh[i - 1];
	}
	for (int j = 1; j <= n; j++) {
		if (m == 0)
			break;
		//int e = 1;
		for (int i = 1; i <= n; i++) {
			if (m == 0) {
				break;
			} else if (m > zjh2[i + 1]) {
				zjh[i] += zjh2[i + 1];
				m -= zjh2[i + 1];
				zjh2[i + 1] = 0;
				zjh2[i] = zjh[i] - zjh[i - 1];
			} else
				break;
		}

	}

	int a = cnt;
	for (int i = 1; i <= n; i++) {
		cnt = 1;
		for (int j = i + 1; j <= n; j++) {
			if (zjh[i] == zjh[j])
				cnt++;
		}
		a = max(cnt, a);
	}
	a + 1;
	cout << a;
	return 0;
}
