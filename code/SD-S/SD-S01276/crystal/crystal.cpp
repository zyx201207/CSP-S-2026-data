#include<bits/stdc++.h>
using namespace std;
long long n,m,sum[500010];
long long a[500010];
inline bool check(long long x){
	for(int i = 1;i+x-1<=n;i++){
		if(a[i+x-1]*x-sum[i+x-1]+sum[i-1]<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++) sum[i] = sum[i-1]+a[i];
	long long l = 0,r = n+1;
	while(l+1<r){
		long long w = (l+r)/2;
		if(check(w)) l = w;
		else r = w;
	}
	printf("%lld\n",l);
	return 0;
}
