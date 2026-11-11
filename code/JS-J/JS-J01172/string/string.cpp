#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;
        char c;
        cin>>x>>c;
        while(x--){
            s+=c;
        }
    }
    ll len=s.size();
    s=" "+s;
    for(ll i=1;i<=len/2;i++){
        if(s[i]!=s[n-i+1]) ans++;
    }
    cout<<ans;
   return 0;
}

