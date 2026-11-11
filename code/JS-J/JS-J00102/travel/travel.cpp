#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;

int main(){
    freopen("travel.in","r",stdin);
    freoprn("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1[0]!=s2[0] || s1[1]!=s2[1]){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(c1[3]=='D' && c1[3]=='F' || c2[3]=='D' && c2[3]=='F'){
        cout<<1;
    }
    else if(c1[3]=='A' && c1[3]=='B' || c2[3]=='A' && c2[3]=='C' || c1[3]=='B' && c1[3]=='A' || c1[3]=='B' && c1[3]=='C' || c1[3]=='C' && c1[3]=='B' ||c1[3]=='C' && c1[3]=='A'){
        cout<<1;
    }
    else {
        cout<<"00";
        return 0;
    }
    if(abs(c1[3]-c2[3])==1)cout<<1;
    else cout<<0;

    return 0;
}
