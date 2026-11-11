#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=5e5+7;
int n,m,ans,qs[N],sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&qs[i]);
	sort(qs+1,qs+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+qs[i];
	int l=1,r=1;
	for(;r<=n;r++){
		while(qs[r]*(r-l+1)-(sum[r]-sum[l-1])>m)l++;
		ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
}