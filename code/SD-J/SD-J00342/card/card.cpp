#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	int k = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		k = k * 10 + (c - '0');
		c = getchar();
	}
	return k * f;
}

const int N = 5e5 + 5;
const int M = 3e5 + 5;

int n, m;
int a[N], cnt[M];
int p[M], num[N];


int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	n = read(), m = read();
	
	bool flag = 0;
	for (int i = 1; i <= n; ++ i) {
		a[i] = read();
		if (a[i] < a[i - 1]) flag = 1;
	}
	
	if (flag == 0) {
		for (int i = 1; i <= n; ++ i) {
			cnt[a[i]] ++;
		}
		for (int i = 1; i <= m; ++ i) {
			cnt[i] += cnt[i - 1];
			printf("%d ", cnt[i]);
		}
		return 0;
	}

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) p[j] = 0;
		for (int j = 1; j <= n; ++ j) num[j] = 0;
		int k = 0;
		for (int j = i; j <= n; ++ j) {
			if (!p[a[j]]) {
				k ++;
				p[a[j]] = k;
				num[k] = a[j];
			} else {
				for (int l = k; l > p[a[j]]; -- l) {
					p[num[l]] = 0;
					num[l] = 0;
				}
				k = p[a[j]];
			}
		}
		for (int j = 1; j <= k; ++ j) cnt[num[j]] ++;
	}
	
	for (int i = 1; i <= m; ++ i) {
		printf("%d ", cnt[i]);
	}
	
	return 0;
}
