#include<bits/stdc++.h>
using namespace std;

int n, m, a[500001], t = 0, s[300001], q[300001];
bool f[300001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		t = 0;
		memset(f, false, sizeof(f));
		for (int j = i; j <= n; j++) {
			s[++t] = a[j];
			if (f[a[j]]) {
				int k1;
				for (int k = 1; k <= t; k++) {
					if (s[k] == a[j])
						k1 = k;
				}
				for (int k = 1; k <= k1; k++) {
					f[s[k]] = false;		
					s[k] = s[k + k1];
				}
				t = k1;
			}
			f[a[j]] = true;
		}
		for (int j = 1; j <= m; j++) {
			if (f[j])
				q[j]++;
		}
	}
	for (int i = 1; i <= m; i++)
		printf("%d ", q[i]);
	return 0;
}
