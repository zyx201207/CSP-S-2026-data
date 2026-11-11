#include<cstdio>
#include<algorithm>
int n;
long long m;
long long a[500010];
long long s[500010];
bool ok(int k){
	for (int l=1;l+k-1<=n;l++){
		int r=l+k-1;
		long long need=a[r]*k-(s[r]-s[l-1]);
		if (need<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	s[1]=a[1];
	std::sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)s[i]=s[i-1]+a[i];
	int L=1,R=n;
	while (L<R){
		int mid=(L+((R-L+1)>>1));
		if (ok(mid))L=mid;
		else R=mid-1;
	}
	printf("%d\n",L);
	return 0;
}
