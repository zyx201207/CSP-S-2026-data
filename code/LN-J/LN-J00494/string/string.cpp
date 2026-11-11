#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string allstring;
    ll n=0;
    cin>>n;
    while(n--){
        ll a=0;char c;
        cin>>a>>c;
        while(a--)allstring+=c;
    }
    ll Size=allstring.size(),sum=0;
    for(ll i=0;i<Size/2;i++){
        if(allstring[i]!=allstring[Size-i-1]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
