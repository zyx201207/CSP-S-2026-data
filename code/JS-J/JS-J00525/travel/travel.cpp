#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=c1[0]-'0',a1=c1[1]-'0',b=c2[0]-'0',b1=c2[1]-'0';
    if(a*10+a1==b*10+b1){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    int x1=s1[0]-'0',x2=s1[1]-'0',y1=s2[0]-'0',y2=s2[1]-'0';
    if((x1*10+x2)==(y1*10+y2)){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    char s=s1[2],ss=s2[2];
    if(s!='C'||ss!='D'){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }
    int x=s1[2]-'0',y=s2[2]-'0';
    if(abs(x-y)==1){
        cout<<"1";
    }
    else{
        cout<<"0";
        return 0;
    }
    return 0;
}
