#include <bits/stdc++.h> 
using namespace std;
long long n, m, a[500005], sum[500005], da = 0;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(int i = 1;i<=n;i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i<=n;i++){
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1;i<=n;i++){
		long long l = i, r = n;
		while(l<r){
			long long mid = (l + r + 1) >> 1, gs = mid - i + 1;
			if(gs * a[mid] - (sum[mid] - sum[i - 1])<=m){
				l = mid;
			}else{
				r = mid - 1;
			}
		}
//		printf("%lld %lld\n", i, l);
		da = max(da, l - i + 1);
	}
	printf("%lld", da);
	return 0;
}
