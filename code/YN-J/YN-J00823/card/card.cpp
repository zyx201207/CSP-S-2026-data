# include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n, m, k = 1, a[maxn], b[maxn], t;
map<int, int>mp1;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int s = a[n];
	for (int i = 1; i <= n; i++) {
		if (a[i] == s) {
			b[t++] = i;
		}
	}
	for (int i = 1; i <= t; i++) {
		cout << b[i];
	}
	for (int i = 1; i <= n; i++) {
		int zc1 = 1;
		for (int i = 1; i < n; i++) {
			map<int, int>mp2;
			if (i == b[zc1]) {
				zc1++;
				continue;
			}
			for (int j = i; j <= b[zc1]; j++) {
				if (mp2[a[j]] == 0) {
					mp1[a[j]]++;
				}
				mp2[a[j]]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d ", mp1[i]);
	}
	return 0;
}