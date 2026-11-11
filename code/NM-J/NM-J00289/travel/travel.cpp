#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string a1,a2;
char b1,b2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else cout<<'1';
    
    b1=s1[2];
    b2=s2[2];
    if(s1[0]==s2[0] && s1[1]==s2[1]){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if((b1<='C' && b1>='A' && b2<='C' && b2>='A') || (b1<='F' && b1>='D' && b2<='F' && b2>='D')){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    if(abs(b1-b2)==1){
        cout<<"1";
    }
    else cout<<"0";
    return 0;
}