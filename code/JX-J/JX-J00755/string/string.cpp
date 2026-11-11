#include<bits/stdc++.h>
#define reg register
#define ll long long
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    reg ll n;
    scanf("%lld",&n);
    vector<ll> a(n+1);
    vector<char> c(n+1);
    string s="";
    for(reg ll i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
        for(reg ll j=1;j<=a[i];j++)
            s+=c[i];
    }
    string s2=s;
    reverse(s2.begin(),s2.end());
    reg ll ans=0;
    for(reg ll i=0;i<s2.size();i++)
        if(s[i]!=s2[i])
            ans++;
    printf("%lld\n",ans/2);
    return 0;
}
