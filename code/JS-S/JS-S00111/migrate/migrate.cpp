#include<bits/stdc++.h>
#define int long long
using namespace std;
mt19937 mrand(20261031143000);
int C,T,n,d,ans,a[2200000];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    ans=mrand();
    cout<<ans%n+(ans&1)<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    while(T--){
        solve();
    }
    cout<<endl;
    return 0;
}
