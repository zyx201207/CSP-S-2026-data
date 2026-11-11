#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e7+5;
ll t,ans;
string a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for(ll i=0;i<t;i++){
        ll x=0;
        string c="";
        cin>>x>>c;
        for(ll j=0;j<x;j++){
            a+=c;
        }
    }
    ll l=ll(a.size()),mid=l/2;

    for(ll i=0;i<mid;i++){
        if(a[i]!=a[l-i-1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
