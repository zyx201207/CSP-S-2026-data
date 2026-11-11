#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> vec[1000005];
ll i;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll t,d;
    cin>>d>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        for(i=1;i<=n;i++){
            ll u,v;
            cin>>u>>v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        if(n%2==0){
            cout<<2<<'\n';
        }else{
            cout<<1<<'\n';
        }
    }
    return 0;
}
