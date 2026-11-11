#include<bits/stdc++.h>
#define int long long
using namespace std;

constexpr int z=200009;
int n,a[z],ans,s[z],r,l=1,lp,rp,ld,rd,d,lc=1,rc;
char c[z];

void solve(){
	while(l<=r){
//		printf("%lld %lld %lld %lld\n",l,r,lc,rc);
		lp=*lower_bound(s+1,s+n+1,l);
		rp=*(lower_bound(s+1,s+n+1,r)-1);
		ld=lp-l+1,rd=r-rp;
		d=min(ld,rd);
		if(c[lc]!=c[rc]){
				ans+=d;
//			printf("add %d now %d\n",d,ans);
		}
		if(d>=ld)++lc;
		if(d>=rd)--rc;
		l+=d,r-=d;
	}
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
        s[i]=s[i-1]+a[i];
	}
	r=s[n];
	rc=n;
    solve();
    printf("%lld",ans);
}
/**
5
1 w
6 r
2 b
7 q
6 h
*/
