#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500005;
long long n,m,a[N],d[N],ds[N],sum,ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	if(n==1){
		printf("1");
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
		sum+=d[i]*i;
	}
	long long i=1,j=2;
	sum=d[1];
	for(;j<=n;){
		if(sum<=m){
			ans=max(ans,j-i);
			j++;
			sum+=(j-i)*d[j-1];
		}
		if(sum>m){
			sum-=(a[j]-a[i]);
			i++;
		}
	}
	printf("%lld",ans+1);
	return 0;
}
