#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n;
long long m;
long long a[N+100],d[N+100],d1[N+100];
long long get(int x,int y) {
	return d1[y]-d1[x]-x*(a[y]-a[x]);
}
int search(int x) {
	int l=1,r=x,mid,ans=x;
	while(l<=r) {
		mid=(l+r)/2;
		if(get(mid,x)>(long long)m) l=mid+1;
			else r=mid-1,ans=mid;
	}
	return x-ans+1;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) d[i]=a[i]-a[i-1];
	for(int i=1;i<=n;++i) d1[i]=d1[i-1]+d[i]*i;
	int ans=1;
	for(int i=1;i<=n;++i) ans=max(ans,search(i));
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/