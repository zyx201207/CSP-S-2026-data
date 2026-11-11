#include<bits/stdc++.h>
using namespace std;
string c,s,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>s>>c2>>s2;
    if(c==c2)  cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(s[0]+s[1]==s2[0]+s2[1])  cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(s[2]<='C' && s2[2]<='C' || s[2]>='D' && s2[2]>='D')  cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if(abs(s[2]-s2[2])==1 || s[2]=='D' && s2[2]=='F' || s2[2]=='D' && s[2]=='F')  cout<<"1";
    else{
        cout<<"0";
        return 0;
    }
    return 0;
}
