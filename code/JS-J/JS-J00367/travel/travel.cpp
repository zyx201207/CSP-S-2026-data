#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    for(int i=1;i<=1;i++){
    if(c1==c2)cout<<"1";
    else {cout<<"0000";
    break;}

    if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<"1";
    else {cout<<"000";
    break;}

    if(s1[2]+s2[2]==131||s1[2]+s2[2]==133||s1[2]+s2[2]==132||s1[2]+s2[2]==138)cout<<"1";
    else {cout<<"00";
    break;}

    if(s1[2]+s2[2]==131||s1[2]+s2[2]==133||s1[2]+s2[2]==138)cout<<"1";
    else cout<<"0";
    }


}
