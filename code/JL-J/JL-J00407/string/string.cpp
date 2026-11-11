#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]!=s[s.size()-1-i]) return false;
    }
    return true;
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    string s="";
    for(ll i=1;i<=n;i++){
        ll a;
        char c;
        cin>>a>>c;
        for(ll i=0;i<a;i++){
            s+=c;
        }
    }
    if(check(s)) {
        cout<<0;
        return 0;
    }
    else{
            ll ans=0;
        for(int i=0;i<s.size();i++){
            if(!check(s)&&s[i]!=s[s.size()-1-i]){
                ans++;
                s[i]=s[s.size()-1-i];
            }
        }
        cout<<ans;
    }
    return 0;
}
