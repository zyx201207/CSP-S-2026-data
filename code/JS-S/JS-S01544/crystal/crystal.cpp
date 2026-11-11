#define FOR(a,b,c) for(ll a=(b);a<=(c);a++)
#define ROF(a,b,c) for(ll a=(b);a>=(c);a--)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef pair<int,int>pii;
typedef unsigned long long ull;
const ll MOD=1,MAXN=555555;
ll n,m,a[MAXN],ans,p=1,now;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    FOR(i,1,n){
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1);
    FOR(i,1,n){
        now+=(i-p)*(a[i]-a[i-1]);
        while(now>m){
            now-=a[i]-a[p];
            p++;
        }
        ans=max(ans,i-p+1);
    }
    printf("%lld",ans);
    return 0;
}
