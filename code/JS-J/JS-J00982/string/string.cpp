#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
string s[200005];
ll j=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++) cin>>a[i]>>s[i];
    ll cnt=0;
    string s1[200005];
    for(ll i=0;i<n;i++){
        while(a[i]--){
            s1[j]=s[i];
            j++;
        }
    }
    for(ll i=0;i<j/2;i++){
    if(s1[i]!=s1[j+1-i]) cnt++;
    }
    cout<<cnt;
    return 0;
}


