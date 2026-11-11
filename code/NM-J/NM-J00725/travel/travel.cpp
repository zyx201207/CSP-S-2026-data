#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    int a=0,b=0;
    bool tf=false,tr=false,tw=false;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }else{
        cout<<0;
        tw=true;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1]&&tw==false){
        cout<<1;
    }else{
        cout<<0;
        tr=true;
    }
    if(s1[2]=='A') a=1;
    if(s1[2]=='B') a=2;
    if(s1[2]=='C') a=3;
    if(s1[2]=='D') a=4;
    if(s1[2]=='F') a=5;
    if(s2[2]=='A') b=1;
    if(s2[2]=='B') b=2;
    if(s2[2]=='C') b=3;
    if(s2[2]=='D') b=4;
    if(s2[2]=='F') b=5;
    if(a<=3&&b<=3&&tr==false&&tw==false){
        cout<<1;
    }else if(a>=4 &&b>=4&&tr==false&&tw==false){
        cout<<1;
    }else{cout<<0;}
    if(a==3&&b==4)tf=true;
    if(a==4&&b==3)tf=true;
    if((a-b==1||b-a==1)&&tf==false&&tr==false&&tw==false){
        cout<<1;
    }else{
        cout<<0;
        }
    return 0;
}
