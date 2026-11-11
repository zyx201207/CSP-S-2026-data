#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],c[500005],s[500005],sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);s[1]=0;
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		s[i]=s[i-1]+c[i];
	}int l=2,r=2,ans=1;
	while(r<=n){
		sum+=c[r]*(r-l+1);
		while(sum>m){
			sum-=(s[r]-s[l-1]);
			l++;
		}
		ans=max(ans,r-l+2);
		r++;
	}printf("%d",ans);
	return 0;
} 
