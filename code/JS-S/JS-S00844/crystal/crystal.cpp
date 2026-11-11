#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,xinzhi=1,ans=0;
ll m,a[500005];
int calc(int x){
	ll steps=0;
	int cnt=0,fl=0;
	for(int i=x-1;i>=1;i--){
		ll dif=a[x]-a[i];
		if(steps+dif<=m){
			cnt++,fl=1;
			steps+=dif;
		}
		else break;
	}
	return cnt+fl;
}
int calc2(ll m){
	if(m>=n*(n+1)/2-1)return n;
	return ceil(-0.5+sqrt(9+8*m)/2);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		if(a[i]-a[i-1]!=1)xinzhi=0;
	if(n<=10000)for(int i=1;i<=n;i++)ans=max(ans,calc(i));
	else if(xinzhi)ans=calc2(m);
	printf("%d",ans);
}
