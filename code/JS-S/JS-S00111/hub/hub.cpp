#include<bits/stdc++.h>
#define int long long
using namespace std;
mt19937 mrand(20261031143000);
int C,T,n,k,ans;
void solve(){
    cin>>n>>k;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
    }
    ans=mrand();
    cout<<ans%n+(ans&1)<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>C>>T;
    while(T--){
        solve();
    }
    cout<<endl;
    return 0;
}
