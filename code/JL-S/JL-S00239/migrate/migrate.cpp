#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000005];
ll dist(ll p,ll q){
    return abs(q-p);
}
bool ck(ll n,ll d){
    for(int i=1;i<=n-3;i++){
        if(d<a[i+2]-a[i]) return false;
    }
    return true;
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll c,T;
    cin>>c>>T;
    while(T--){
        ll n,d;
        cin>>n>>d;
        int t=n;
        if(ck(n,d)){
            cout<<abs(n-3)<<'\n';
            n=t;
            continue;
        }
else{
    cout<<abs(n-4)<<'\n';
    n=t;
    continue;
}
    }
    return 0;
}
