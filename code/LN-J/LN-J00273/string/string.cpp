#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s="";
ll a,b,x;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(ll i=0;i<a;i++){
        cin>>b>>c;
        for(ll j=0;j<b;j++){
            s+=c;
        }
    }
    for(ll l=0,r=s.length()-1;l<r;l++,r--){
        if(s[l]!=s[r]){
            x++;
        }
    }
    cout<<x;
    fclose("string.in");
    fclose("string.out");
    return 0;
}
