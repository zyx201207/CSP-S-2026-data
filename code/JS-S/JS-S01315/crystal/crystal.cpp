#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+10;
ll a[MAXN];
bool cmp(ll x,ll y){return x>y;}
void solve(){
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n,cmp);
    ll ans=1;
    for(ll i=1,pos=1,sum=0,pre=1;i<=n&&pos<n;i++){
        if(a[i]==a[i-1])continue;
        sum-=(a[pre]-a[i])*(pos-i+1);
        pre=i;
        while(sum+a[i]-a[pos+1]<=m&&pos<=n)sum+=a[i]-a[++pos];
        ans=max(ans,pos-i+1);
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    solve();
    return 0;
}
