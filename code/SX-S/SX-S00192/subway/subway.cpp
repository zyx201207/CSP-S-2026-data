#include <bits/stdc++.h>
using namespace std;

struct station {
	int line[500];
	int st;
	int sz[500];
	int bh;
};

struct line {
	int zs;
	int zhan[500005];
};

struct plan {
	int bb;
	int ee;
};

int main() {
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	int c1, n, m, d, q;
	cin >> c1 >> n >> m >> d >> q;
	station a[m + 2];
	line b[n + 2];
	plan c[q + 2];
	for (int i = 1; i <= m; i++) {
		cin >> a[i].st;
		a[i].bh = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i].zs;
		for (int j = 1; j <= b[i].zs * 2; j++) {
			int z;
			cin >> z;
			b[i].zhan[z] += 1;
			int sj;
			cin >> sj;
			a[z].line[i] = z;
			a[z].sz[i] = sj;
		}
	}
	for (int i = 1; i <= q; i++)
		cin >> c[i].bb >> c[i].ee;

	return 0;
}