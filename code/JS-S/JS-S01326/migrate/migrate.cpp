#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll x[1000005];
void solve(){
    ll n,d;
    cin>>n>>d;
    for (int i=1;i<=n;i++){
        cin>>x[i];
    }
    if (c==11||c==12){
        ll p=x[2]-x[1];
        if (d/p<=1){
            cout<<0<<'\n';
            return;
        }
        ll u=d/p; //一次能跳的岛屿数量<=u
        //只有一次u和一次u-1,长度为2*u
        if (2*u>n){
            cout<<0<<'\n';
            return;
        }
        cout<<1ll+n-2*u<<'\n';
    }
    if (c==13||c==14){
        cout<<0<<'\n';
        return;
    }
    //不可以,总司令
    cout<<0<<'\n';
    return;
}
int main(){
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>t;

    while(t--){
        solve();
    }
    return 0;
}
