#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, p[N], ct;
long long m, a[N], b[N], c, mx=INT_MIN, f, d;
long long q[N];
int main(){
	cin.tie(0)->sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		c += a[i];
	}
	if (n <= 5000){
		sort(a+1, a+n+1);
		for (int i = n; i >= 2; i--){
			for (int j = i-1; j >= 1; j--){
				long long h = a[i];
				for (int k = h; k <= h+m; k++){
					long long v = 0;
					for (int t = j; t <= i; t++)
						v += k - a[t];
					if (v <= m) q[++ct]= i-j+1;
				}
			}
		}
		sort(q+1, q+ct+1);
		printf("%lld", q[ct]);
	}
	else {
		long long cnt = 0, ans = 0, mb = a[n];
		for (int i = n; i >= 1; i--){
			cnt += (mb - a[i]);
			if (cnt > m) break;
			ans++; 
		}
		printf("%lld", ans);
	}
	return 0;
}