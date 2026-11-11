#include<bits/stdc++.h>
using std::pair;
using std::make_pair;
typedef long long ll;
typedef long double ld;
const ll maxn=1e16+7;
const ll N=500010;
ll n,m,a[N],pre[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin>>n>>m;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    std::sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        ll l=1,r=i,res=i;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m){
                res=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        ans=std::max(ans,i-res+1);
    }
    std::cout<<ans<<"\n";
    return 0;
}
