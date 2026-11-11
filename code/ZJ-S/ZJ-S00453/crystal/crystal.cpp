#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,a[N],sum[N];
int n;
bool check(int x){
	for(int i=1;i<=n-x+1;++i){
		int ll=i,rr=i+x-1;
		int midd=rr;
		long long sum3=a[midd]*(midd-ll+1)-sum[midd]+sum[ll-1];
		if(sum3<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",a+i);
	}

	sort(a+1,a+1+n);	
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}
