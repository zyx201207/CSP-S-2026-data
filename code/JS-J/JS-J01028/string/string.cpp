#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll t;
    cin>>t;
    string s="";
    ll a;char c;
    for(ll k=1;k<=t;k++){
        cin>>a>>c;
        for(ll i=1;i<=a;i++){
            s+=c;
        }
    }
    int len=s.size();
    if(len%2==1){
        string s1="";
        string s2="";
        int cnt=0;
        for(ll i=0;i<len/2;i++) s1+=s[i];
        for(ll i=len/2+1;i<len;i++) s2+=s[i];
        for(ll i=0;i<len/2;i++){
            if(s1[i]!=s2[len/2-1-i]) cnt++;
        }
        cout<<cnt;
    }
    else{
        string s1="";
        string s2="";
        int cnt=0;
        if(s[len/2-1] != s[len/2]) cnt++;
        for(ll i=0;i<len/2-1;i++) s1+=s[i];
        for(ll i=len/2+1;i<len;i++) s2+=s[i];
        for(ll i=0;i<len/2-1;i++){
            if(s1[i]!=s2[len/2-2-i]) cnt++;
        }
        cout<<cnt;
    }
    return 0;
}
