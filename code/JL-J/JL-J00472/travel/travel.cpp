#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int f1=0,f=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1;
    cin>>s2;
    cin>>s3;
    cin>>s4;
    if(s1[0]==s3[0]&&s1[1]==s3[1]){
        f=1;
        f1=1;
    }
    if(f==1&&f1==1)cout<<1;
    else if(f==0){
        cout<<0;
    }
    f=0;
    if(s2[0]==s4[0]&&s2[1]==s4[1]&&f1==1)f=1;
    if(f==1&&f1==1)cout<<1;
    else if(f==0){
        cout<<0;
    }
    if((s2[2]<='C'&&s4[2]<='C'&&f==1&&f1==1)||(s2[2]>='D'&&s4[2]>='D'&&f==1&&f1==1))cout<<1;
    else cout<<0;
    if(f1==1&&f==1&&(s2[2]=='A'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='A'||s2[2]=='C'&&s4[2]=='B'||s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='F'||s2[2]=='F'&&s4[2]=='D'))cout<<1;
    else{
        cout<<0;
    }
    return 0;
}
