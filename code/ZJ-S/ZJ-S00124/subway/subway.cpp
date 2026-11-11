#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX = 100111;
const int INF = 10000100;
int c, n, m, d, q, w[MAX], a[MAX][MAX], t[MAX][MAX], k[MAX], o[MAX], top;

void Dijiesite(int i) {
	
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &m, &n, &d, &q);
	int s[MAX];
	for (int i = 1; i <= n; ++i)
		scanf("%d", &w[i]), s[i] = 0;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &k[i]);
		for (int j = 1; j <= k[i]; ++j) {
			scanf("%d", &a[i][j]);
			scanf("%d", &t[a[i][j]][i]);
			s[a[i][j]]++;
		}
		top = max(top, k[i]);
	}
	if (m <= 2) {
		int b[MAX];
		int a1[MAX];
		int a2[MAX];
		int mindist = INF;
		for (int i = 1; i <= n; ++i)
			b[i] = s[i] = 0, a1[i] = a2[i] = INF;
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= k[i]; ++j) {
				ll x;
				s[a[i][j]]++;
				if (i == 1)
					a1[a[i][j]] = t[a[i][j]][i];
				if (i == 2)
					a2[a[i][j]] = t[a[i][j]][i];
				b[a[i][j]] += t[a[i][j]][i];
				if (s[a[i][j]] == 2)
					mindist = min(mindist, b[a[i][j]]);
			}
		}
		for (int i = 1; i <= q; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			int ans = w[x] + w[y];
			if (s[x] == 2 || s[y] == 2) {
				int z = INF;
				z = min(z, a1[x] + a1[y]);
				z = min(z, a1[x] + a2[y] + mindist);
				z = min(z, a2[x] + a1[y] + mindist);
				z = min(z, a2[x] + a2[y]);
				printf("%d\n", ans + z);
			} else
				printf("%d\n", ans + mindist + b[x] + b[y]);

		}
	}
	else {
		if (top <= 2) {
			
		}
	} 
}
