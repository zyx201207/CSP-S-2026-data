#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(((s1[0]-'0')==(s2[0]-'0'))&&((s1[1]-'0')==(s2[1]-'0'))){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if((0<=(s1[2]-'A')&&(s1[2]-'A')<=2&&0<=(s2[2]-'A')&&(s2[2]-'A')<=2)||(3<=(s1[2]-'A')&&(s1[2]-'A')<=4&&3<=(s2[2]-'A')&&(s2[2]-'A')<=4)){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
         cout<<1;
    }
    else{
        cout<<"0";
        return 0;
    }
}
