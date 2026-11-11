#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,l,r,mid,ma,ans;
ll m,a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=1,r=i;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m){
				r=mid-1;
				ma=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-ma+1);
	}
	printf("%d",ans);
}