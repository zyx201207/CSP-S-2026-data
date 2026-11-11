#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200010], ans;
/*
void f(long long cs, long long i, long long t){
	if(cs == m){
		if(t > ans) ans = t;
	}
	for(int j = i + 1; j <= n - m + cs; j++){
		f(cs + 1, j, t * a[j]);
	}
}
*/
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
//	f(0, 1, 1);
//	cout << ans;
//	/*
	if(m == 1){
		int maxn = -1;
		for(long long i = 1; i <= n; i++){
			if(a[i] > maxn){
				maxn = a[i];
			}
		}
		printf("%d", maxn);
		return 0;
	}
	if(m == 2){
		long long maxn = -1;
		for(long long i = 1; i <= n; i++){
			for(long long j = i + 1; j  <= n; j++){
				if(a[i] & a[j] > maxn){
					maxn = a[i] & a[j];
				}
			}
		}
		printf("%d", maxn);
		return 0;
	}
	if(m == 3){
		long long maxn = -1;
		for(long long i = 1; i <= n; i++){
			for(long long j = i + 1; j <= n; j++){
				for(long long k = j + 1; k <= n; k++){
					if(a[i] & a[j] & a[k] > maxn){
						maxn = a[i] & a[j] & a[k];
					}
				}
			}
		}
		printf("%d", maxn);
		return 0;
	}
	if(m == 4){
		long long maxn = -1;
		for(long long i = 1; i <= n; i++){
			for(long long j = i + 1; j <= n; j++){
				for(long long k = j + 1; k <= n; k++){
					for(long long k = j + 1; k <= n; k++){
						if(a[i] & a[j] & a[k] > maxn){
							maxn = a[i] & a[j] & a[k];
						}
					}
				}
			}
		}
		printf("%d", maxn);
		return 0;
	}
	if(m == n){
		long long ans = a[1];
		for(long long i = 2; i <= n; i++){
			ans &= a[i];
		}
		printf("%d", ans);
	}
//	*/
	return 0;
}
