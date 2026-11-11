#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr int maxn=5e5+5;
int n;
ll m;
ll a[maxn],dif[maxn];
ll sum1[maxn],sum2[maxn];
bool ck(ll x){
    for (int i=1;i+x-1<=n;i++){
        int r=i+x-1;
        ll w=sum2[r]-sum2[i];
        w-=(ll)i*(sum1[r]-sum1[i]);
        if (w<=m) return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++){
        dif[i]=a[i]-a[i-1];
        sum2[i]=sum2[i-1]+i*dif[i];
        sum1[i]=a[i];
    }
    ll L=1,R=n+1;
    ll ans=1;
    while (L<R){
        ll mid=(L+R)>>1;//risk
        if (ck(mid)){
            ans=mid;
            L=mid+1;
        }
        else{
            R=mid;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
