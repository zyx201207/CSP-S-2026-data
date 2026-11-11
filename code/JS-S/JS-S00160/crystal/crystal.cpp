#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
using ll=long long;
int n,ans;
ll m,a[N];
bool check(ll x){
    ll s=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=x) break;
        s+=(ll)(x-a[i]);
    }
    return s<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    ll l=a[1],r=a[n];
    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    for(int i=1;i<=n;i++) if(a[i]<=l) ans++;
    printf("%d",ans);
    return 0;
}
