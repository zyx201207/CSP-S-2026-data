#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<"1";
    else{cout<<"0000";return 0;}
    if(s1.substr(0,2)==s2.substr(0,2))cout<<"1";
    else{cout<<"000";return 0;}
    string a=s1.substr(2,1),b=s2.substr(2,1);
    if((a=="A"||a=="B"||a=="C")&&(b=="A"||b=="B"||b=="C"))cout<<"1";
    else if((a=="D"||a=="E")&&(b=="D"||b=="E"))cout<<"1";
    else{cout<<"00";return 0;}
    if((a=="A"&&b=="B")||(b=="A"&&a=="B")||(a=="B"&&b=="C")||(b=="B"&&a=="C")||(a=="D"&&b=="E")||(b=="D"&&a=="E"))cout<<"1";
    else cout<<"0";
    return 0;
}
