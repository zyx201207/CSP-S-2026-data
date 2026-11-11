#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
    int n,d,c=0,lst=0,f=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(i==1){
            lst=x;
            continue;
        }
        if(x-lst!=c&&i!=2) f=1;
        c=x-lst;
        lst=x;
        if(c>d) f=1;
    }
    if(f==1||d!=2){
        cout<<0<<'\n';
        return;
    }
    if(d==2) cout<<n-3<<'\n';
    return;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--) solve();
    return 0;
}
