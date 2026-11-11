#include<bits/stdc++.h>
#define int long long
using namespace std;
int cnt,ans,n,m,A[500007];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
	sort(A+1,A+1+n);
	for(int L=1,R=2;R<=n;R++){
		cnt+=(A[R]-A[R-1])*(R-L);
		while(cnt>m){
			cnt-=(A[R]-A[L]);
			L++;
		}
		ans=max(ans,R-L+1);
	}
	printf("%lld",ans);
	return 0;
}
