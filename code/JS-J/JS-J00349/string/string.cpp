#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ans=0;
    cin>>n;
    vector<ll>a(n);
    vector<char>b(n);
    string s;
    for(ll i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(ll i=0;i<n;i++){
       for(ll j=0;j<a[i];j++) s+=b[i];
    }
    ll l=s.size();
    for(ll i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
