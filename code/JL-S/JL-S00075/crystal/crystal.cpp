#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N];
ll n,m;
ll sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    ll ans=1,cnt=1;
    for(ll i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        ll x=a[i]*(i-cnt),tot=(sum[i-1]-sum[cnt-1]);
        if((x-tot)<=m)
            ans=max(ans,i-cnt+1);
        else if(cnt<i){
            cnt++;
            i--;
        }
    }
    cout<<ans;
    return 0;
}
