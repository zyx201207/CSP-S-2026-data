#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","W",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    string line1,line2;
    line1=s1.substr(0,2);line2=s2.substr(0,2);
    if(line1==line2){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    char id1=s1[2],id2=s2[2];
    if((id1>='A'&&id1<='C'&&id2>='A'&&id2<='C')||(id1>='D'&&id1<='F'&&id2>='D'&&id2<='F')){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if((id1=='B'||id2=='B')||(id1=='D'&&id2=='F')||(id1=='F'&&id2=='F')){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
