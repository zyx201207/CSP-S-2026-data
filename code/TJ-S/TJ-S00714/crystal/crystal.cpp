#include<cstdio>
#include<algorithm>
#include<map>
const int maxn=500005;
long long a[maxn];
int n;
long long m; 
bool ok(long long x){
	long long sum=0;
	for(int i=1;i<=n&&a[i]<=x;i++){
		sum+=x-a[i];
		//if(sum>m) break;
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	long long l=-1000000000000,r=1000000000000;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(ok(mid)) l=mid+1;
		else r=mid-1;
	}
	int c=0;
	for(int i=1;i<=n&&a[i]<=l;i++) c++;
	printf("%d\n",c);
	return 0;
}
