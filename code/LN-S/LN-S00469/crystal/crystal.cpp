
#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL N = 7e5+100;
LL ask[N];
LL F[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	LL n,m;
	scanf("%lld%lld",&n,&m);
	if(n==1){
		cout<<n;
		return 0;
	}
	for(LL i=1;i<=n;i++) scanf("%lld",&F[i]);
	sort(F+1,F+n+1);
	LL l=1,r=0;
	LL sum=0;
	LL ans=0;
	for(LL i=1;i<=n;i++){
		if(i==1) continue;
		r++;
		sum+=F[i-1];
		while((r-l+1)*F[i]-sum>m&&l<=r){
			l++;
			sum-=F[l-1];
		}
		if((r-l+1)*F[i]-sum<=m) ans=max(ans,r-l+1);	
	}
	cout<<ans+1;
	return 0;
}

