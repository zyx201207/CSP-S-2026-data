#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1145;
const long long inf=1e18+1145;

int n,ans=1;
long long m,now_cost,a[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    
    int l=1;    
    for(int i=2;i<=n;i++){
    	now_cost+=(i-l)*( a[i]-a[i-1] );
    	if(m<now_cost) {
    		now_cost-=a[i]-a[l];
    		++l;
		}
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
 }

