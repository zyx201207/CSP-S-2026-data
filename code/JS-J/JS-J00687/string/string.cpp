#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    ll cnt=0;
    ll a;
    char ch;
    while(n--){
        cin>>a>>ch;
        for(int i=1;i<=a;i++){
            s+=ch;
        }
        cnt+=a;
    }
    ll ans=0;
    for(ll j=0;j<cnt/2;j++){
        if(s[j]!=s[cnt-j-1]){
            ans++;
            s[j]=s[cnt-j-1];
        }
    }
    cout<<ans;
    return 0;
}
