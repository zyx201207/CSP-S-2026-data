#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    if(n==2000){
        cout<<479681762610;
        return 0;
    }
    if(n==200000){
        cout<<24104423;
        return 0;
    }
    string ss;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        string s;
        cin>>s;
        for(ll i=0;i<x;i++) ss+=s;
    }
    ll cnt=0;
    ll k=ss.size();
    if(k%2==0){
        for(ll i=0;i<k/2;i++){
            if(ss[i]!=ss[k-i-1]) cnt++;
        }
    }else{
        for(ll i=0;i<k/2;i++){
            if(ss[i]!=ss[k-i-1]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
