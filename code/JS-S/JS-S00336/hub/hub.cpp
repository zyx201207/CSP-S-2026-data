#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c=0,t=0;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        ll n=0,k=0;
        cin>>n>>k;
        for(ll i=1;i<n;i++){
            ll u=0,v=0;
            cin>>u>>v;
        }
        if(n==k){
            cout<<"0\n";
            continue;
        }
        if(k>=n/2){
            cout<<1;
        }
        else{
            cout<<ceil(((n-(2*k))*1.0)/8.0)+1<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
