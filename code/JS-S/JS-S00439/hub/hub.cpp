#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll c,t,n,k,x;
ll u[N],v[N];
void solve(){
    cin>>n>>k;
    for(ll i=1;i<n;i++) cin>>u[i]>>v[i];
    x=(n-1)/2+2;
    cout<<(x-k+3)/4<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--) solve();
    return 0;
}
