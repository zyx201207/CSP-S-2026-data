#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    for(ll i=0;i<c1.size();i++){
        if(c1[i]!=c2[i]){
            cout<<"0000";
            return 0;
        }
    }
    cout<<1;
    for(ll i=0;i<s1.size()-1;i++){
        if(s1[i]!=s2[i]){
            cout<<"000";
            return 0;
        }
    }
    cout<<1;
    if(s1[2]=='A'&&s2[2]=='B')cout<<11;
    else if(s2[2]=='A'&&s1[2]=='B')cout<<11;
    else if(s1[2]=='A'&&s2[2]=='C')cout<<10;
    else if(s1[2]=='C'&&s2[2]=='A')cout<<10;
    else if(s1[2]=='B'&&s2[2]=='C')cout<<11;
    else if(s1[2]=='C'&&s2[2]=='B')cout<<11;
    else if(s1[2]=='D'&&s2[2]=='F')cout<<11;
    else if(s1[2]=='F'&&s2[2]=='D')cout<<11;
    else cout<<"00";
    return 0;
}
//long long!!!
//freopen!!!
