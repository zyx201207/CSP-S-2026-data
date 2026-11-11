#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n,a[N],sum[N],ans,m,l,r,qwq = 1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i <= n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;++i){
		sum[i] = sum[i - 1] + a[i];
	}
/*
	for(int i = 1;i <= n;++i){
		printf("%lld ",a[i]);
	}
	printf("\n");
	for(int i = 1;i <= n;++i){
		printf("%lld ",sum[i]);
	}
	printf("\n");
*/
	for(int i = 1;i <= n;++i){
		l = 1,r = i - 1,ans = -1;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a[i] * (i - 1 - mid + 1) - (sum[i - 1] - sum[mid - 1]) <= m){
				ans = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
//		printf("sum:%lld,i:%lld,ans:%lld\n",a[i] * (i - 1 - ans + 1) - sum[i - 1] + sum[ans - 1],i,ans);
		if(ans != -1){
			qwq = max(qwq,i - ans + 1);
		}
	}
	printf("%lld",qwq);
	return 0;
}
