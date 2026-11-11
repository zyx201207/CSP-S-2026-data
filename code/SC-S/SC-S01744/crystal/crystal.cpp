#include<bits/stdc++.h>
using namespace std;
const int N=5e5+50;
long long a[N],sum[N],m;
int n;
int did(int x){
	int l=1,r=x,mid,ret=1;
	while(l<=r){
		mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-
		   (sum[x]-sum[mid-1])<=m){
			ret=x-mid+1;
			r=mid-1;
		}
		else l=mid+1;
	} 
	return ret;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++)
		ans=max(ans,did(i));
	printf("%d",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/