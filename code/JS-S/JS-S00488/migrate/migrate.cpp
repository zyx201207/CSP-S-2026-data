#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        ll pd=1;
        ll ch=0;
        for(ll i=1;i<=n;++i){
            cin>>a[i];
            if(i>2){
                ch=a[i]-a[i-1];
                if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
                    pd=0;
                }
            }
        }
        if(pd=1){
            if(d/ch!=2){
                cout<<0<<"\n";
            }
            else{
                cout<<n-3<<"\n";
            }
        }
        else cout<<0<<"\n";
    }
    return 0;
}
