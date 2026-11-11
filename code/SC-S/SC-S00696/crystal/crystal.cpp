#include <bits/stdc++.h>
using namespace std;

int n, ans;
long long M, a[500010], qz[500010];

int main (){
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	scanf ("%d%lld", &n, &M);
	for (int i = 1; i <= n; i++){
		scanf ("%lld", &a[i]);
	}
	sort (a + 1, a + n + 1);
	for (int i = n; i >= 1; i--)
		qz[i] = qz[i + 1] + a[n] - a[i];
//	for (int i = 1; i <= n; i++)
//		printf ("%lld ", qz[i]);
//	printf ("\n");
	for (long long i = 1; i <= n; i++){
		long long l = 0, r = i, m = (l + r) / 2;
		while (l + 1 < r){
			if (qz[m] - qz[i] - (i - m) * (a[n] - a[i]) <= M){
				r = m;
			}
			else{
				l = m;
			}
			m = (l + r) / 2;
		}
		ans = max (ans * 1ll, i - r + 1ll);
	}
	printf ("%d", ans);
	return 0;
}