#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,s,a[500010];
int n,l,ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	l=1;
	for(int i=2;i<=n;i++){
		while(s+(ll)(i-l)*(a[i]-a[i-1])>m){
			s-=a[i-1]-a[l];l++;
		}
		s+=(i-l)*(a[i]-a[i-1]);
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}
