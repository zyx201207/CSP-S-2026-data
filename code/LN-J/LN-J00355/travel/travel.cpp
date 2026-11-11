#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    if(a2[2]=='D')a2[2]++;
    if(a4[2]=='D')a4[2]++;
    if(a1==a3)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    if(a2[0]==a4[0] && a2[1]==a4[1])cout<<1;
    else {
        cout<<"000";
        return 0;
    }
    if((a2[2]-'D')*(a4[2]-'D')>0) cout<<1;
    else {
        cout<<"00";
        return 0;
    }
    if(abs((int)(a2[2]-a4[2]))==1)cout<<1;
    else cout<<0;
   return 0;
}
