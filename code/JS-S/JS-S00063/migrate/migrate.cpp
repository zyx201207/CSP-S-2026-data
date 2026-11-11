#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+9;
int a[maxn];
int n,d;
void solve1(){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i+d+1<=n){
            if(i+d+d-1<=n) ans+=d-1;
            else ans+=n-i-d;
        }
    }
}


void solve(){

    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(i+d+1<=n){
            if(i+d+d-1<=n) ans+=d-1;
            else ans+=n-i-d;
        }
    }
    cout<<ans<<'\n';


}



signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int C,_;
    cin>>C>>_;
    while(_--){
        solve();
    }
    return 0;
}
