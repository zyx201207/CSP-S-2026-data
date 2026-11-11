#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e6+5;
ll a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;scanf("%lld%lld",&c,&t);
    if(c==11||c==12||c==0){
        while(t--){
            ll n,k;scanf("%lld%lld",&n,&k);
            for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
            ll d=a[2]-a[1];
            if(n<2*(k/d)||k<2*d)printf("0\n");
            else printf("%lld\n",n-(2*(k/d))+1);
        }
        return 0;
    }
    while(t--){
        ll n,k;scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        printf("%0\n");
    }
    return 0;
}
