#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[1000005];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<ll>());
    ll ans=a[1];
    for(int i=1;i<m;i++){
        ans&=a[i+1];
    }
    cout<<ans;
    return 0;
}
