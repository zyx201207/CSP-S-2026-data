#include<iostream>
#include<algorithm>
typedef long long ll;
const int N=5e5+114;

ll sum[N],m,a[N];
ll n;

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
        scanf("%lld",a+i);
    
    std::sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];

    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll l=i,r=n;

        while(l<=r){
            ll mid=(l+r)>>1;
            if(sum[mid]-sum[i-1]+m>=a[mid]*(mid-i+1))
                l=mid+1;

            else r=mid-1;
        }
        ans=std::max(ans,l-i);
        
    }

    printf("%lld",ans);
    return 0;
}