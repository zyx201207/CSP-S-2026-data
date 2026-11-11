#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],s[500005];
int hb(int x){
	int l = 0,r = x,md;
	if(a[x] * x - s[x] <= m) return x;
	while(r-l > 1){
		md = (l + r) >> 1;
		if(a[x] * (x - md) - (s[x] - s[md]) <= m) r = md;
		else l = md;
	}
	return x-r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++) s[i] = s[i-1] + a[i];
	int ans = 1;
	for(int i = 1;i<=n;i++){
		ans = max(ans,hb(i));
//		printf("%d\n",hb(i));
	}
	printf("%d",ans);
	return 0;
}
