#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,ans;
bool ok=1;
__int128 x;
ll a[N],sum[N];
unsigned long long m;
void solve(){
    ll um=0;
    for(int i=1;i<=n-1;i++){
        if(um*x<=m){
            ans=max(ans,um+1);
        }
        if(m<x*um) break;
        m=m-x*um;
        um++;
    }
    cout<<ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(a[n]==a[1]){
        cout<<n;
        return 0;
    }
    x=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=x){
            ok=0;
            break;
        }
    }
    if(ok&&n>=N){
        solve();
        return 0;
    }
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    ll l=1,r=2;
    while(l<r&&r<=n){
        if(sum[r]-sum[l]<=m){
            ans=max(ans,r-l+1);
            r++;
        }
        else l++;
    }
    cout<<ans;
    return 0;
}
