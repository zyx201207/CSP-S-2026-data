#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,s1,line1=0,line2=0,side1=0,side2=0,seat1=0,seat2=0;
    string a2,s2;
    cin>>a1>>a2>>s1>>s2;

    line1=(a2[0]-'0')*10+(a2[1]-'0');
    line2=(s2[0]-'0')*10+(s2[1]-'0');

    if(a2[2]=='A' || a2[2]=='B' || a2[2]=='C') side1=1;
    else side1=2;
    if(s2[2]=='A' || s2[2]=='B' ||s2[2]=='C') side2=1;
    else side2=2;

    if(a2[2]=='A') seat1=1;
    else if(a2[2]=='B') seat1=2;
    else if(a2[2]=='C') seat1=3;
    else if(a2[2]=='D') seat1=4;
    else seat1=5;

    if(s2[2]=='A') seat2=1;
    else if(s2[2]=='B') seat2=2;
    else if(s2[2]=='C') seat2=3;
    else if(s2[2]=='D') seat2=4;
    else seat2=5;

    if(a1!=s1) cout<<"0000"<<endl;
    else if(line1 != line2) cout<<"1000"<<endl;
    else if(side1!=side2) cout<<"1100"<<endl;
    else if(abs(seat1-seat2)!=1) cout<<"1110"<<endl;
    else cout<<"1111"<<endl;
    return 0;
}
