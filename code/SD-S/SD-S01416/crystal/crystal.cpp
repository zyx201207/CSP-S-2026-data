#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=500002;
ll n,m,a[N],pre[N],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		pre[i]=pre[i-1]+a[i];
	for(ll i=1;i<=n;++i){
		ll l=1,r=i,mid;
		for(;l<r;){
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m)
				r=mid;
			else
				l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld\n",ans);
	return 0;
}
