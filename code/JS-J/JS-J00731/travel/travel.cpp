#include<bits/stdc++.h>
using namespace std;
int a,b,c,r1,r2;
int main(){
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';
    }else{
        cout<<'0';
        a=1;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&a==0){
    cout<<'1';
    }else{
        cout<<'0';
        b=1;
    }
    r1=s1[2]-'0'-16;
    r2=s2[2]-'0'-16;
    if(r1<=3&&r2<=3&&b==0){
        cout<<'1';
    }else if(r1<=5&&r1>3&&r2<=5&&r2>3&&b==0){
        cout<<'1';
    }else{
        cout<<'0';
        c=1;
    }
    if(s1[2]-s2[2]==1&&c==0){
        cout<<'1';
    }else if(s2[2]-s1[2]==1&&c==0){
        cout<<'1';
    }else{
        cout<<'0';
    }
}
