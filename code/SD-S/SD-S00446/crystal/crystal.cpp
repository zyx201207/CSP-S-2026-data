#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,ans;
long long a[1000001],s[1000001],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,tmp=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
				tmp=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-tmp+1);
	}
	printf("%d",ans);
	return 0;
}
