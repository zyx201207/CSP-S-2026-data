#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string c1,s1,c2,s2;
int bl[122];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bl[int('A')]=int('A');
    bl[int('B')]=int('B');
    bl[int('C')]=int('C');
    bl[int('D')]=int('D');
    bl[int('F')]=int('D')+1;
    string cb1=s1.substr(0,2),cb2=s2.substr(0,2);
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(c1==c2&&cb1==cb2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if(c1==c2&&cb1==cb2&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
        cout<<1;
    }
    else{
        cout<<0;
    }
    //cout<<bl[int(s1[2])]+1<<" "<<bl[int(s2[2])]<<" "<<bl[int(s1[2])]-1<<" "<<bl[int(s2[2])];
    if(c1==c2&&cb1==cb2&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))&&(bl[int(s1[2])]+1==bl[int(s2[2])]||bl[int(s1[2])]-1==bl[int(s2[2])])){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
