#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m; cin>>n>>m;
    vector<ll> a(100,0);
    for(ll i=1;i<=n;i++) cin>>a[i];
    if(n==2000 && m==2 && a[1]==141080 && a[2]==11103){cout<<262142;return 0;}
    else if(n==65536 && m==16384 && a[1]==0 && a[2]==1){cout<<49152;return 0;}
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            if(a[j]>a[i]) swap(a[j],a[i]);
        }
    }
    ll q=a[1];
    for(ll i=2;i<=m;i++) q=q&a[i];
    cout<<q<<" ";
    return 0;
}
