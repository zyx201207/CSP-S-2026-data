#include <bits/stdc++.h>
int N;
long long M,a[500009];
signed main(void) {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&N,&M);
	for(int i=1;i<=N;i++) {
		scanf("%lld",&a[i]);
	}
	std::sort(a+1,a+N+1);
	int l=1;long long ww=0;
	int as=1;
	for(int i=2;i<=N;i++) {
		ww+=1ll*(a[i]-a[i-1])*(i-l);
		while(ww>M) {
			ww-=(a[i]-a[l]);
			l++;
		}
		as=std::max(as,i-l+1);
	}
	printf("%d",as);
}
