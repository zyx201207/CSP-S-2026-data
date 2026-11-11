#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll t;
    scanf("%lld",&t);
    string s="";
    while(t--){
        ll x;
        char c;
        cin>>x>>c;
        for(int i=1;i<=x;++i){
            s+=c;
        }
    }
    ll ans=0,q=s.size(),mn=q/2;
    for(int i=q-1;i>=mn;i--){
        if(s[i]!=s[q-i-1]){
            ans++;
        }
    }
    printf("%lld",ans);
    return 0;
}
