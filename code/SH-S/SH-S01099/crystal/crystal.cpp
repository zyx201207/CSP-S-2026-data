#include<bits/stdc++.h>
#define N ((int)(5e5)+10)
using namespace std;
using ll=long long;
int n;
ll m,a[N],sum[N];
bool check(int mid){
	ll mn=INT64_MAX;
	for(int i=mid;i<=n;i++)
		mn=min(mn,mid*a[i]-(sum[i]-sum[i-mid])); 
	return mn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	partial_sum(a+1,a+n+1,sum+1);
	int l=0,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%d",l);
}
