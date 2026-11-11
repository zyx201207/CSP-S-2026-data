#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 1;

int num[MAXN];
char chr[MAXN];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> num[i] >> chr[i];
	}
	long long ans = 0;
	int i = 1, j = n;
	while(i < j) {
		int ni = num[i], nj = num[j];
		int *pi = &num[i], *pj = &num[j];
		if (chr[i] != chr[j])
			ans += 1ll * min(ni, nj);
		if (ni >= nj) {
			*pi -= nj;
			j--;
		}
		if (nj >= ni) {
			*pj -= ni;
			i++;
		}
	}
	cout << ans;
	return 0;
}
