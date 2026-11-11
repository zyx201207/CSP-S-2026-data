#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string s3;
    string s4;
    for(int i=1;i<=s1.size();i++){
        if(s1[i]>=0&&s1[i]<=9){
            s3+=s1[i];
        }
    }
    for(int i=1;i<=s2.size();i++){
        if(s2[i]>=0&&s2[i]<=9){
            s4+=s2[i];
        }
    }
    char a=s1[2];
    char b=s2[2];
    bool x=0;
    if(a>b){
        char c=a;
        a=b;
        b=c;
    }
    if(c1==c2){
        cout<<1;
        x=1;
    }
    else{
        cout<<0;
        x=0;
    }
    if(s3==s4&&x==1){
        cout<<1;
        x=1;
    }
    else{
        cout<<0;
        x=0;
    }
    if(((a<'C'&&b<='C')||(a=='D'&&b=='F'))&&x==1){
        cout<<1;
        x=1;
    }
    else{
        cout<<0;
        x=0;
    }
    if(a+1==b&&x==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
