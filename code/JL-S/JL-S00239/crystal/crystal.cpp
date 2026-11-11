#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
ll n,m;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];

    }
    ll ans=0;
    sort(a+1,a+1+n);
    ll r=1;
   while(1){
    ll cnt=0;
    for(ll i=1;i<=r;i++) cnt+=a[r]-a[i];
    if(cnt<m){
        r++;
        continue;
    }
    if(cnt==m){
        ll o=0;
        for(ll i=r;i<=n;i++){
            if(a[r]==a[r+1]) o++;
            else{
                break;
            }
            cout<<r+o;
            break;
        }
        break;
    }
    if(cnt>m){
        cout<<r-1;
        break;
    }
   }
    return 0;
}
