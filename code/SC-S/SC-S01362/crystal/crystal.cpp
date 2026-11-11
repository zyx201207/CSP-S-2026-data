#include <bits/stdc++.h>
#define ll long long
using namespace std;
//10^18:longlong
ll a[500010],c[500010],S[500010],sum=0,ans=0,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		S[i]=S[i-1]+a[i]-a[1];
		c[i]=(a[i]-a[1])*i-S[i];
		if(m>=c[i])ans=i;
	}ll nxt;
	for(int j=2;j+ans-1<n;j++){
		nxt=ans;
		for(int i=0;j+ans+i<=n;i++){
			ll s=c[j+ans+i]-c[j]-(a[j+ans+i]-a[j])*(j-1);
			if(s<=m)nxt=max(nxt,ans+i+1);
			else break;
		}ans=nxt;
	}
	printf("%lld\n",ans);
//	for(int i=1;i<=n;i++){
//		printf("%lld ",c[i]);
//	}printf("\n");
//	for(int i=1;i<=n;i++){
//		printf("%lld ",S[i]);
//	}printf("\n");
//	for(int i=1;i<=n;i++){
//		printf("%lld ",a[i]);
//	}
}