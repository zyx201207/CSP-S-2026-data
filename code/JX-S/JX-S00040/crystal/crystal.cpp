#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,m;
ll a[N],sum[N];
bool check(ll x){
    ll minCost=INF;
    for(int i=x;i<=n;i++){
        ll cost=(__int128)x*a[i]-(sum[i]-sum[i-x]);
        minCost=min(minCost,cost);
    }
    if(minCost<=m)return true;
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    ll l=1,r=n,ans=1;
    while(l<=r){
        ll mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
