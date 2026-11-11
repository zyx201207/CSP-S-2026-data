#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
long long a[MAXN];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	long long ans = 0xfffffffff;
	sort(a + 1, a + n + 1);
	for(int i = n - m; i <= n; i++){
		ans &= a[i];
	}
	printf("%lld\n", ans);
	return 0;
}