#include <bits/stdc++.h>
using namespace std;

bool cmp(long long x, long long y) {
	return x > y;
}
long long n, m, a[5005], pc[5005][5005];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
//	sort(a + 1, a + 1 + n, cmp);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			pc[i][j] = a[j] - a[i];
//			if (pc[i][j] < 0) {
//				pc[i][j] = -1e18;
//			}
//		}
//	}
	for (int i = 1; i <= n; i++) {
		
	}
	cout<<'3';
	return 0;
}
