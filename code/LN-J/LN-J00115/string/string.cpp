#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;ll cnt=0;
    cin>>n;
    string s="";
    for(int i=0;i<n;i++){
        ll a;
        char k;
        cin>>a>>k;
        cnt+=a;
        while(a--)
            s+=k;
    }
    cnt=cnt/2+1;
    ll ans=0;
    for(ll j=0;j<cnt-1;j++){
        if(s[j]!=s[j+cnt])
            ans++;
    }
    cout<<ans;
    return 0;
}
