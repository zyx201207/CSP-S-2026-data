#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], sum[200005], l = 1, la = 0, r, ra = 0, da = 0;
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1;i<=n;i++){
		scanf("%lld %c", &a[i], &c[i]);
		ra += a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	r = n;
	while(l<r){
		long long p = sum[l] - la, q = ra - sum[r - 1];
		if(p<q){
			if(c[l]!=c[r]){
				da += p;
			}
			l++;
			la += p;
			ra -= p;
		}else if(p==q){
			if(c[l]!=c[r]){
				da += p;
			}
			l++;
			r--;
			la += p;
			ra -= p;
		}else{
			if(c[l]!=c[r]){
				da += q;
			}
			r--;
			ra -= q;
			la += q;
		}
	}
	printf("%lld", da);
	return 0;
}
