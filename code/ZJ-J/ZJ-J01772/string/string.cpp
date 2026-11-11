#include <bits/stdc++.h>
using namespace std;
long long n, a[300001], l = 1, r = 1, ans, s, w, k1, e1[300001], k2, e2[300001];
char c[300001], c1[300001], c2[300001];
int main(){
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w" , stdout);
	scanf ("%lld" ,&n);
	for (int i = 1;i <= n;i ++){
		cin >>a[i]>>c[i];
		s += a[i];
	}
	for (int i = 1;i <= n;i ++){
		if (s / 2 - w > a[i]){
			w += a[i];
			k1 ++;
			e1[k1] = a[i];
			a[i] = 0;
			c1[k1] = c[i];
		} else {
			k1 ++;
			a[i] -= s / 2 - w;
			e1[k1] = s / 2 - w;
			c1[k1] = c[i];
			break;
		}
	}
	w = 0;
	for (int i = n;i >= 1;i --){
		if (s / 2 - w > a[i]){
			w += a[i];
			k2 ++;
			e2[k2] = a[i];
			a[i] = 0;
			c2[k2] = c[i];
		} else {
			k2 ++;
			a[i] -= s / 2 - w;
			e2[k2] = s / 2 - w;
			c2[k2] = c[i];
			break;
		}
	}
	while (l <= k1){
		if (e1[l] > e2[r]){
			if (c1[l] != c2[r]){
				ans += e2[r];
			}
			e1[l] -= e2[r];
			r ++;
		} else if (e2[r] > e1[l]){
			if (c1[l] != c2[r]){
				ans += e1[l];
			}
			e2[r] -= e1[l];
			l ++;
		} else {
			if (c1[l] != c2[r]){
				ans += e2[r];
			}
			e2[r] = e1[l] = 0;
			l ++;
			r ++;
		}
	}
	printf ("%lld" ,ans);
	return 0;
}

