#include <bits/stdc++.h>
using namespace std;

int c, t, n, f[200010], b[200010];
long long a[200010], d, ans; 

int main (){
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	scanf ("%d%d", &c, &t);
	while (t--){
		scanf ("%d%lld", &n, &d);
		for (int i = 1; i <= n; i++)
			scanf ("%lld", &a[i]);
		int l = 1, r = 1;
		for (int i = 1; i <= n; i++){
			while (a[r] - a[i] <= d && r <= n)
				r++;
			r--;
			while (a[i] - a[l] > d)
				l++;
			f[i] = l;
			b[i] = r;
		}
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++){
				if ((b[i] < j) && (b[i] == f[j] + 1) && (f[j] > i)){
					ans++;
				}
			}
		}
		printf ("%lld\n", ans);
		ans = 0;
	}
	return 0;
}