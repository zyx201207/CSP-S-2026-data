#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],l,r,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
    for(l=1,r=1;r<=n;r++){
	    m-=(r-l)*(a[r]-a[r-1]);
	    while(l<r&&m<0)m+=a[l++];
        if(m>=0)ans=max(ans,r-l+1);
    }
    printf("%lld",ans); 
	return 0;
}

