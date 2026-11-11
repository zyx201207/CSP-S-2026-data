#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,c=0,s[500005],l,r,mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		l=0;r=i;
		while(l<=r){
			mid=(l+r)>>1;
			if((i*a[i]-s[i])-(mid*a[i]-s[mid])<=m){
				ans=max(ans,i-mid);
				r=mid-1;
			}
			else    l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}
