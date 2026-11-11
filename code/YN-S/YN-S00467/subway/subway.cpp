#include <bits/stdc++.h>
using namespace std;

struct st {
	int ti;
	int next[300];
} s[300];
int pl[300][2];
int c, n, m, d, q, k, a;

void sc(int h, int e, int t) {
	if (h == 0) {
		return;
	}
	int x = 0;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> s[i].ti;
	}
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> a;
			cin >> s[a].ti;
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> pl[i][0] >> pl[i][1];
		//hao nan... wo bu xie le
	}

	return 0;
}