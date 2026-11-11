#include<bits/stdc++.h>
using  namespace std;
#define ll long long
ll a[1000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        cout<<ceil(n/2)-d<<endl;
    }
    return 0;
}
