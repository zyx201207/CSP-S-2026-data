#include<bits/stdc++.h>
#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;
ll t;
ll a[2000005];
ll v;
int main(){
     freopen("migrate.in","r",stdin);
      freopen("migrate.out","w",stdout);
    cin>>v;
    cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        ll x=a[2]-a[1],sum=2;

        for(ll i=3;i<=n;i++){
            if(a[i]-a[i-1]==x){
                sum++;
            }
        }
        if(sum==n&&n>2*d){
           cout<<n-3<<"\n";
        }else if(d>n){
            cout<<0<<"\n";
        }
    }







    return 0;
}
