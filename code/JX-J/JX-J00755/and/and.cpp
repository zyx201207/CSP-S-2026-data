#include<bits/stdc++.h>
#define reg register
#define ll long long
using namespace std;
inline bool cmp(reg ll x,reg ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    reg ll n,m;
    scanf("%lld%lld",&n,&m);
    vector<ll> a(n+1);
    for(reg ll i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a.begin()+1,a.begin()+n+1,cmp);
    reg ll ans=a[1];
    for(reg ll i=1;i<=m;i++)
        ans&=a[i];
    printf("%lld\n",ans);
    return 0;
}
