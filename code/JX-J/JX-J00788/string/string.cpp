#include<bits/stdc++.h>
using namespace std;
vector<char>s,st;
typedef  long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++){
        ll x;
        char c;
        cin.ignore();
        cin>>x>>c;
        for(ll i=0;i<x;i++){
            s.push_back(c);
        }

    }
    st=s;
    for(ll i=0;i<s.size()/2;i++){
        s[s.size()-i-1]=s[i];
    }
    ll sp=0;
    for(ll i=0;i<s.size();i++){
        if(s[i]!=st[i])sp++;
    }
    cout<<sp;
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
