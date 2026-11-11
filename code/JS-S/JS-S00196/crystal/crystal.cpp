#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define debug(x) cout<<#x<<": "<<x<<'\n';
#define debug2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<'\n';
#define debug3(x,y,z) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<" "<<#z<<": "<<z<<'\n';
const ll MAXN=5e5+5;
ll n,m,a[MAXN],sum[MAXN];
ll cha(ll L,ll R){
    if (L==R) return 0;
    ll r=R-1;
    return (r-L+1)*a[R]-(sum[r]-sum[L-1]);
}
void solve(){
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        sum[i]=a[i]+sum[i-1];
    int j=1,ans=1;
    for (int i=1;i<=n;i++){
        while (cha(j,i)>m) j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    solve();
    return 0;
}
